#include <bits/stdc++.h>
using namespace std;

void print(int y, int d, int m) {
	if (d == 0) {
		for (int i = 0; i <= 10; ++i) putchar(i < 1 || y == m ? '*' : ' ');
		puts("");
		return;
	}
	int x = (y - m) / d;
	if (x > 0 && y == d * x + m) {
		for (int i = 0; i <= 10; ++i) putchar(i < 1 || i == x ? '*' : ' ');
		puts("");
	}
	else {
		for (int i = 0; i <= 10; ++i) putchar(i > 0 ? ' ' : '*');
		puts("");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int d, m;
		scanf("%d %d", &d, &m);
		printf("y = %dx + %d\n", d, m);
		for (int y = d * 10 + m; y > 0; --y) {
			print(y, d, m);
		}
		puts("***********");
	}
	return 0;
}