#include <bits/stdc++.h>
using namespace std;

int main() {
	char a, b, p[5]="<^>v";
	int d;
	scanf("%c %c %d", &a, &b, &d);

	d %= 4;
	int start = 0;
	for (int i = 0; i < 4; ++i) {
		if (p[i] == a) start = i;
	}

	int cw = start, ccw = start;
	for (int i = 0; i < d; ++i) {
		cw = (cw + 1) % 4;
		ccw = (ccw - 1 + 4) % 4;
	}

	bool CW = (p[cw] == b), CCW = (p[ccw] == b);
	if (CW ^ CCW) {
		if (CW) puts("cw");
		else puts("ccw");
	} else puts("undefined");

	return 0;
}