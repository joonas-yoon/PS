#include <cstdio>

int main() {
	int a, d, k;
    scanf("%d %d %d", &a, &d, &k);
    if ((k - a + d) % d) return puts("X"), 0;
    int n = (k - a + d) / d;
    if (n < 1) puts("X");
    else printf("%d\n", n);
	return 0;
}