#include <cstdio>

int n, v[20];
int ans[6];

void lotto(int k, int sel = 0) {
	if (sel >= 6) {
		for (int i = 0; i < 6; ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
		return;
	}
	if (k >= n) return;

	ans[sel] = v[k];
	lotto(k + 1, sel + 1);
	lotto(k + 1, sel);
}

int main() {
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		lotto(0);
		puts("");
	}
	return 0;
}