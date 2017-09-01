#include <cstdio>

int main() {
	int a, b, c;
	while (~scanf("%d %d %d", &a, &b, &c)) {
		if (!a && !b && !c) break;
		for (int i = 0; i < c; ++i) {
			int t = a + b;
			a = b;
			b = t;
		}
		printf("%d\n", b);
	}
	return 0;
}