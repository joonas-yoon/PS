#include <cstdio>

int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	r--, c--;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			putchar(((i + j) % 2) ^ ((r + c) % 2) ? '.' : 'v');
		puts("");
	}
	return 0;
}