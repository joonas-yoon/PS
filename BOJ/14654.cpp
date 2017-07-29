#include <bits/stdc++.h>
using namespace std;

char win(int a, int b) {
	if (a == b) return -1;
	if (a == 1) return b == 3 ? 0 : 1;
	if (a == 2) return b == 1 ? 0 : 1;
	return b == 2 ? 0 : 1;
}

int main() {
	int n, a[300], b[300];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

	int lastPerson = win(a[0], b[0]);
	int len = 1, ans = 1;
	for (int i = 1; i < n; ++i) {
		char w = win(a[i], b[i]);
		if (w == -1 || lastPerson != w) {
			lastPerson ^= 1;
			len = 1;
			continue;
		}
		else {
			len++;
		}
		ans = max(ans, len);
	}

	printf("%d", ans);

	return 0;
}