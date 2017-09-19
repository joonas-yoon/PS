#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n, k, s[101][101];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d ", &s[i][j]);

	int stat = INF;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			for (int c = 0; c < n; ++c) {
				int wins = 0;
				for (int i = 0; i < n; ++i) {
					wins += s[a][0] >= s[i][0] && s[b][1] >= s[i][1] && s[c][2] >= s[i][2];
				}
				if (wins >= k) {
					stat = min(stat, s[a][0] + s[b][1] + s[c][2]);
				}
			}
		}
	}
	printf("%d\n", stat);
	return 0;
}