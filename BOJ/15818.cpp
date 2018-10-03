#include <cstdio>

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	int r = 1, x;
	while (n--) {
		scanf("%d", &x);
		r = ((long long)r * x) % p;
	}
	printf("%d\n", r);
	return 0;
}