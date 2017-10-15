#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, ans = -1;
		scanf("%d", &n);
		int m = n % 4;
		if (m == 0) ans = n / 4;
		else if (m == 1 && n >= 9) ans = (n - 9) / 4 + 1;
		else if (m == 2 && n >= 6) ans = (n - 6) / 4 + 1;
		else if (m == 3 && n >= 15) ans = (n - 15) / 4 + 2;
		printf("%d\n", ans);
	}
	return 0;
}