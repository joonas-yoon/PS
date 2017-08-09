#include <cstdio>
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) putchar('1');
	for (int i = 1; i < k; ++i) putchar('0');
	return 0;
}