#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[101];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int x = a[(n + i) / 2];
		if (i % 2 == 0) x = a[(n - 1 - i) / 2];
		printf("%d ", x);
	}
	return 0;
}