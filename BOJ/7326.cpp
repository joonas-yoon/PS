#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x != y && x - 2 != y) {
			puts("No Number");
			continue;
		}

		int g = x + y;
		if (g % 4) g -= x == y;
		else g -= x != y;
		printf("%d\n", g);
	}
	return 0;
}