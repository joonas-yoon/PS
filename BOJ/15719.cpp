#include <cstdio>

int a[312501];

void _set(int x) {
	a[x / 32] |= 1 << (x % 32);
}

bool _get(int x) {
	return a[x / 32] & (1 << x % 32);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (_get(x)) return printf("%d\n", x), 0;
		_set(x);
	}
	return 0;
}