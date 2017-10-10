#include <cstdio>

int main() {
	int n, a[100100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int ans = 0, asum = 0, bsum = 0;
	for (int b, i = 0; i < n; ++i) {
		scanf("%d", &b);
		if ((asum += a[i]) == (bsum += b)) ans = i + 1;
	}
	printf("%d\n", ans);
	return 0;
}