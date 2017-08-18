#include <cstdio>

int f(int);
int g(int);

int main() {
	int n;
	while (~scanf("%d", &n)) {
		printf("%d\n", f(n));
	}
	return 0;
}

int f(int n) {
	if (n < 1) return 1;
	if (n % 2) return 0;
	return 2 * g(n - 1) + f(n - 2);
}

int g(int n) {
	if (n < 0 || n % 2 == 0) return 0;
	return g(n - 2) + f(n - 1);
}