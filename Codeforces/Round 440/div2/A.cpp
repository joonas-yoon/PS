#include <bits/stdc++.h>
using namespace std;

bool a[10], b[10];

bool ok(int n) {
	bool ay = 0, by = 0;
	while (n > 0) {
		ay |= a[n % 10];
		by |= b[n % 10];
		n /= 10;
	}
	return ay && by;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int x, i = 0; i < n; ++i) {
		scanf("%d ", &x), a[x] = 1;
	}
	for (int x, i = 0; i < m; ++i) {
		scanf("%d ", &x), b[x] = 1;
	}

	for (int i = 1; i < 1e10; ++i) {
		if (ok(i)) return printf("%d\n", i), 0;
	}

	return 0;
}