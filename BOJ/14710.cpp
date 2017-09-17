#include <cstdio>

int main() {
	int h, m;
	scanf("%d %d", &h, &m);
	h %= 30;
	puts(12 * h == m ? "O" : "X");
    return 0;
}