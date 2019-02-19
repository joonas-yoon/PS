#include <cstdio>
#include <algorithm>

int main() {
	int n, h, a[10001];
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		h += a[i] <= h;
	}
	printf("%d\n", h);
	return 0;
}