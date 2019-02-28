#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char s[90];
		scanf("%s ", s);
		int ans = 0, cnt = 0;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == 'O') {
				ans += ++cnt;
			} else {
				cnt = 0;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}