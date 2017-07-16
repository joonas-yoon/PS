#include <cstdio>

int main() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		printf("%d.", a / b);
		int len = 0, m = a % b;
		while (len++ < 15) {
			m *= 10;
			printf("%d", m / b);
			m %= b;
			if (m == 0) break;
		}
		puts("");
	}
	return 0;
}