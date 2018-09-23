#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		puts(!(n & (n - 1)) ? "1" : "0");
	}
	return 0;
}