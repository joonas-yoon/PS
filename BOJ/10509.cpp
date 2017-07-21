#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> dial[10];

int n, ans;

void dfs(int k, int dep = 3) {
	if (dep <= 0) return;

	if (abs(ans - n) > abs(k - n)) {
		ans = k;
	}

	for(auto& next : dial[k % 10]) {
		dfs(10 * k + next, dep - 1);
	}
}

int main() {
	char s[4][4] = { "123", "456", "789", "-0-" };
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < 4; ++i) {
			if (!(s[i][j] >= '0' && s[i][j] <= '9')) continue;
			for (int _i = i; _i < 4; ++_i) {
				for (int _j = j; _j < 3; ++_j) {
					if (s[_i][_j] >= '0' && s[_i][_j] <= '9') {
						dial[s[i][j] - '0'].push_back(s[_i][_j] - '0');
					}
				}
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = INF;
		for (int i = 0; i < 10; ++i) dfs(i);
		printf("%d\n", ans);
	}
	return 0;
}