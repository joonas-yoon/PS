#include <cstdio>

#define INF 987654321

int main() {
	int n;
	char s[101][101];
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) gets(s[i]);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int white = 0;
		for (int j = 0; j < n; ++j) {
			if (s[i][j] != '.') white = 0;
			else white++;

			if (white >= 2) {
				++ans;
				white = -INF;
			}
		}
	}
	printf("%d ", ans);
	ans = 0;
	for (int i = 0; i < n; ++i) {
		int white = 0;
		for (int j = 0; j < n; ++j) {
			if (s[j][i] != '.') white = 0;
			else white++;

			if (white >= 2) {
				++ans;
				white = -INF;
			}
		}
	}
	printf("%d", ans);
	return 0;
}