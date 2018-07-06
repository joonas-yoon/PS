#include <cstdio>

int main() {
	int k, m;
	while (~scanf("%d %d", &k, &m) && k && m) {
		bool chk[10001] = {};
		for (int x, i = 0; i < k; ++i) {
			scanf("%d", &x);
			chk[x] = true;
		}
		bool yes = true;
		for (int i = 0; i < m; ++i) {
			int c, r, z = 0;
			scanf("%d %d", &c, &r);
			for (int x, i = 0; i < c; ++i) {
				scanf("%d", &x);
				z += chk[x];
			}
			yes &= z >= r;
		}
		puts(yes ? "yes" : "no");
	}
	return 0;
}