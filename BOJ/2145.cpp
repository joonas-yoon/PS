#include <cstdio>

int solve(int n) {
	int r = 0;
	while (n > 0) {
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		int ans = solve(n);
		while (ans > 9) ans = solve(ans);
		printf("%d\n", ans);
	}
	return 0;
}