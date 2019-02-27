#include <cstdio>
#include <algorithm>

int main() {
	int a[5];
	for (int i = 0; i < 5; ++i)
		scanf("%d", &a[i]);

	std::sort(a, a + 5);

	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				ans += a[i] + a[j] > a[k];
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}