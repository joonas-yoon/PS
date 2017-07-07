#include <cstdio>

typedef long long lld;

int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		int n = min(a, b);
		for (int i = n - 1; i > 1; --i) n *= i;
		printf("%d\n", n);	
	}
	return 0;
}