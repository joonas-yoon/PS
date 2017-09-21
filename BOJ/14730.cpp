#include <cstdio>
int main() {
	int n, fr[101], po[101];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &fr[i], &po[i]);
	int ans[101] = {};
	for (int i = 0; i < n; ++i) {
		if (po[i] > 0) {
			ans[i] = fr[i] * po[i];
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) res += ans[i];
	printf("%d\n", res);
	return 0;
}