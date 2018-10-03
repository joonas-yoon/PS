#include <cstdio>
#include <algorithm>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (c) {
		if (a < b) {
			a++;
		}
		else {
			b++;
		}
		c--;
	}
	printf("%d\n", std::min(a, b) * 2);
	return 0;
}