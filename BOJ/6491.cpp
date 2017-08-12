#include <cstdio>

char* solve(int n) {
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) sum += i;
	}
	if (sum == n) return "PERFECT";
	if (sum < n) return "DEFICIENT";
	return "ABUNDANT";
}

int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		printf("%d %s\n", n, solve(n));
	}
	return 0;
}