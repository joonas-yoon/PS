#include <cstdio>

int startPoint(int n) {
	int y = 0;
	for (int i = 1, k = 1; k <= n; k += i, ++i) y = k;
	return y;
}

int main() {
	int n;
	scanf("%d", &n);
	int sp = startPoint(n);
	int x = 0, i = 1, k = n;
	while (k > 0) {
		x = i;
		k -= i++;
	}
	printf("%d %d\n", x - (n - sp), n - sp + 1);
	return 0;
}