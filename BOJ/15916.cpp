#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	lld k;
	scanf("%lld", &k);

	if (n == 1 && a[0] == k) return puts("T"), 0;

	for (int i = 1; i < n; ++i) {
		if (a[i - 1] >= i * k && a[i] <= (i + 1LL) * k) return puts("T"), 0;
	}
	puts("F");

	return 0;
}