#include <cstdio>
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (0 < x) puts(0 < y ? "1" : "4");
	else puts(0 < y ? "2" : "3");
	return 0;
}