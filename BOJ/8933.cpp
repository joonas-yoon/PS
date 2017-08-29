#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

int ord(char c) {
	for (int i = 0; i < 4; ++i)
		if (c == "ACGT"[i]) return i;
	return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		char w[60001];
		scanf("%d %s ", &k, w);
		vector<vector<int>> v;
		int len = strlen(w);
		vector<int> temp(4, 0);
		for (int i = 0; i <= len; ++i) {
			if (i >= k || i == len) {
				v.push_back(temp);
				temp[ord(w[i - k])]--;
			}
			temp[ord(w[i])]++;
		}

		std::sort(v.begin(), v.end());
		int ans = 1, mcs = 1;
		for (int i = 1; i < v.size(); ++i) {
			if (v[i] == v[i - 1]) {
				mcs++;
				ans = max(ans, mcs);
			}
			else {
				mcs = 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}