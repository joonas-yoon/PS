#include <cstdio>
#include <algorithm>

int f(int h, int w) {
	if (h <= w) return 2 * (h - 1);
	return 2 * std::min(h, w) - 1;
}

int main() {
	int h, w;
    scanf("%d %d", &h, &w);
	printf("%d\n", f(h, w));
	return 0;
}