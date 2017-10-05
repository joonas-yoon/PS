#include <cstdio>

int a[10240];

void solve(int l, int r, const int n) {
	if (l > r) return;
	int right = l + 1;
	while (right < n && a[right] < a[l]) right++;
	solve(l + 1, right - 1, n);
	solve(right, r, n);
	printf("%d\n", a[l]);
}

int main() {
	int n = 0;
	while (~scanf("%d ", &a[n])) n += 1;
	solve(0, n - 1, n);
	return 0;
}