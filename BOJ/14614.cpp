#include <bits/stdc++.h>

int main() {
	int a, b;
	char c[101];
	scanf("%d %d %s", &a, &b, c);
	int _c = (c[strlen(c) - 1] - '0') % 2;
	for (int i = 0; i < _c; ++i) a ^= b;
	printf("%d", a);
	return 0;
}