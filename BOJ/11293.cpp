#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	int T;
	scanf("%d ", &T);
	for (int tc = 1; tc <= T; ++tc) {
		printf("Customer %d\n", tc);
		int n, k;
		scanf("%d ", &n);
		char s[10][55] = {};
		for (int i = 0; i < n; ++i) {
			char _s[55]; gets(_s);
			for (int j = 0, k = 0; _s[j]; ++j) {
				if (_s[j] != ' ') s[i][k++] = _s[j];
			}
		}
		scanf(" %d", &k);
		while (k--) {
			int id, a1, a2;
			char c1, c2;
			scanf("%d %d %d %c %c ", &id, &a1, &a2, &c1, &c2);
			puts(s[id - 1][a1 - 1] == c1 && s[id - 1][a2 - 1] == c2 ? "correct" : "error");
		}
	}
	return 0;
}