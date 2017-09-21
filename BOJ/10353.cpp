#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	while (n--) {
		int x;
		scanf("%d ", &x);
		if (x <= 2) {
			puts("YES");
			continue;
		}
		int dh[] = { 1,2,0 }, dw[] = { 1,0,2 };
		bool ans = false;
		for (int i = 0; i < 3; ++i) {
			int hh = h - dh[i], ww = w - dw[i];
			ans |= x <= min(hh, ww) && (ww % x == 0) && (hh % x == 0);
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}