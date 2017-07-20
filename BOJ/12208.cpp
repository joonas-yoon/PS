#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;

void compress(vector<vector<int>>& a, char dir) {
	if (dir == 'l') {
		for (int i = 0; i < n; ++i) {
			vector<int> newRow(n, 0);
			for (int j = 0, m = 0; j < n && m < n; ++j) {
				if (a[i][j] == 0) continue;

				int next = j + 1;
				if (next >= n) newRow[m++] = a[i][j];
				else {
					while (next < n && a[i][next] == 0) next++;
					if (next < n && a[i][j] == a[i][next]) {
						newRow[m++] = a[i][j] * 2;
						j = next;
					}
					else {
						newRow[m++] = a[i][j];
					}
				}
			}
			a[i] = newRow;
		}
	}
	else if (dir == 'r') {
		for (int i = 0; i < n; ++i) {
			vector<int> newRow(n, 0);
			for (int j = n - 1, m = n - 1; j >= 0 && m >= 0; --j) {
				if (a[i][j] == 0) continue;

				int next = j - 1;
				if (next < 0) newRow[m--] = a[i][j];
				else {
					while (next >= 0 && a[i][next] == 0) next--;
					if (next >= 0 && a[i][j] == a[i][next]) {
						newRow[m--] = a[i][j] * 2;
						j = next;
					}
					else {
						newRow[m--] = a[i][j];
					}
				}
			}
			a[i] = newRow;
		}
	}
	else if (dir == 'u') {
		vector<vector<int>> a2(n, vector<int>(n, 0));
		for (int j = 0; j < n; ++j) {
			for (int i = 0, m = 0; i < n && m < n; ++i) {
				if (a[i][j] == 0) continue;

				int next = i + 1;
				if (next >= n) a2[m++][j] = a[i][j];
				else {
					while (next < n && a[next][j] == 0) next++;
					if (next < n && a[i][j] == a[next][j]) {
						a2[m++][j] = a[i][j] * 2;
						i = next;
					}
					else {
						a2[m++][j] = a[i][j];
					}
				}
			}
		}
		a = a2;
	}
	else if (dir == 'd') {
		vector<vector<int>> a2(n, vector<int>(n, 0));
		for (int j = 0; j < n; ++j) {
			for (int i = n - 1, m = n - 1; i >= 0 && m >= 0; --i) {
				if (a[i][j] == 0) continue;

				int next = i - 1;
				if (next < 0) a2[m--][j] = a[i][j];
				else {
					while (next >= 0 && a[next][j] == 0) next--;
					if (next >= 0 && a[i][j] == a[next][j]) {
						a2[m--][j] = a[i][j] * 2;
						i = next;
					}
					else {
						a2[m--][j] = a[i][j];
					}
				}
			}
		}
		a = a2;
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for(int t = 0; t < T; ++t){
		printf("Case #%d:\n", t + 1);
		char dir[6] = {};
		scanf("%d %s ", &n, dir);
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d ", &a[i][j]);

		compress(a, dir[0]);

		for(auto& row : a){
			for (int& el : row) printf("%d ", el);
			puts("");
		}
	}
	return 0;
}