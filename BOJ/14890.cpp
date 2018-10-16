#include <bits/stdc++.h>
using namespace std;

bool isOk(vector<int>& v, int l) {
	int n = v.size();
    
	for (int i = 1; i < n; ++i)
		if (abs(v[i - 1] - v[i]) > 1)
			return false;
    
	vector<bool> used(n, false);
	for (int i = 0; i + 1 < n; ++i) {
		if (v[i] == v[i + 1]) continue;
		else if (v[i] < v[i + 1]) {
			if (i + 1 - l < 0) return false;
			int p = v[i];
			for (int j = 0; j < l; ++j) {
				if (used[i - j] || p != v[i - j]) return false;
				used[i - j] = true;
			}
		}
		else {
			if (i + l >= n) return false;
			int p = v[i + 1];
			for (int j = 1; j <= l; ++j) {
				if (used[i + j] || p != v[i + j]) return false;
				used[i + j] = true;
			}
		}
	}

	return true;
}

int main() {
	int n, l;
	int a[101][101];
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> hor, ver;
		for (int j = 0; j < n; ++j) {
			ver.push_back(a[j][i]);
			hor.push_back(a[i][j]);
		}
		ans += isOk(ver, l) + isOk(hor, l);
	}
	printf("%d\n", ans);

	return 0;
}