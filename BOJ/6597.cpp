#include <bits/stdc++.h>
using namespace std;

int len;
char po[55], io[55];

int index(char *s, char c) {
	for (int i = 0; s[i]; ++i) if (s[i] == c) return i;
	return -1;
}

void solve(int pl, int pr, int il, int ir) {
	if (pl > pr || il > ir) return;
	int iroot = index(io, po[pl]);
	int leftWidth = iroot - il;
	int rightWid = ir - iroot;
	solve(pl + 1, pl + leftWidth, il, iroot - 1);
	solve(pl + leftWidth + 1, pr, iroot + 1, ir);
	putchar(po[pl]);
}

int main() {
	while (~scanf("%s %s ", po, io)) {
		len = strlen(po);
		solve(0, len - 1, 0, len - 1);
		puts("");
	}
	return 0;
}