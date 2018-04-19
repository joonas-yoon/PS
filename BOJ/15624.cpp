#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int a = 1, b = 0, t;
	for (int i = 0; i < n; ++i) {
		t = b;
		b = a;
		a = (a + t) % (int)(1e9 + 7);
	}
	printf("%d\n", b);

	return 0;
}
