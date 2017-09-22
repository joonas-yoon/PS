#include <cstdio>

int main() {
	int n, tc = 0;
	char s[12][4] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	while (~scanf("%d ", &n) && n) {
		int fq[13] = {};
		for (int m, d, y, i = 0; i < n; ++i) {
			scanf("%d %d %d", &d, &m, &y);
			fq[m-1] += 1;
		}
		printf("Case #%d:\n", ++tc);
		for (int i = 0; i < 12; ++i) {
			printf("%s:", s[i]);
			while (fq[i]--) putchar('*');
			puts("");
		}
	}
	return 0;
}