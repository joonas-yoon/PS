#include <cstdio>

int main() {
	int a, b;
	char c;
	while (~scanf("%d %c %d ", &a, &c, &b)) {
		if (!a && !b) break;
		if (c == 'W') b *= -1;
		if (a + b < -200) {
			puts("Not allowed");
			continue;
		}
		printf("%d\n", a + b);
	}
	return 0;
}