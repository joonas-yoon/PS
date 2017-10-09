#include <cstdio>

bool isLeapYear(int y) {
	return (!(y % 4) && y % 100) || !(y % 400);
}

int main() {
	int y, m, d;
	static int mon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (~scanf("%d %d %d", &d, &m, &y) && y) {
		for (int i = 0; i < m; ++i) 
			d += (i == 2 && isLeapYear(y)) + mon[i];
		printf("%d\n", d);
	}
	return 0;
}