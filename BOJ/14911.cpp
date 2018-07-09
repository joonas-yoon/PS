#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[20], n = 0;
	while (~scanf("%d", &a[n])) n++;
	int x = a[--n];

	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (binary_search(a + i + 1, a + n, x - a[i]))
			printf("%d %d\n", a[i], x - a[i]), ans++;
	}
	printf("%d\n", ans);

	return 0;
}