#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

int main() {
	lld a, b;
	scanf("%lld %lld", &a, &b);
	if (b - a >= 10LL) puts("0");
	else {
		lld x = 1;
		for (lld i = a + 1; i <= b; ++i) {
			x = (x * i) % 10;
		}
		printf("%lld\n", x);
	}
	return 0;
}