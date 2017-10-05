#include <bits/stdc++.h>
using namespace std;

int n, po[1024], io[1024];

int index(int *a, int k) {
	for (int i = 0; i < n; ++i) if (a[i] == k) return i;
	return -1;
}

void solve(int pl, int pr, int il, int ir) {
	if (pl > pr || il > ir) return;
	int iroot = index(io, po[pl]);
	int leftWidth = iroot - il;
	int rightWid = ir - iroot;
	solve(pl + 1, pl + leftWidth, il, iroot - 1);
	solve(pl + leftWidth + 1, pr, iroot + 1, ir);
	printf("%d ", po[pl]);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &po[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &io[i]);
		solve(0, n - 1, 0, n - 1);
		puts("");
	}
	return 0;
}