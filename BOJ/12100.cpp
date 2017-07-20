#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

int compress(vector<vector<int>>& a, char dir) {
	int n = a.size(), ret = 0;
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

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) ret = max(ret, a[i][j]);
	}
	return ret;
}

int dfs(vector<vector<int>>& a, int dep) {
	if (dep >= 5) return 0;
	int n = a.size();

	int r = 0;
	vector<vector<int>> bak = a;
	for (int i = 0; i < 4; ++i) {
		r = max(r, compress(bak, "lrud"[i]));
		r = max(r, dfs(bak, dep + 1));
		bak = a;
	}
	return r;
}

int main() {
	int n;
	scanf("%d ", &n);
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d ", &a[i][j]);

	printf("%d", dfs(a, 0));

	return 0;
}