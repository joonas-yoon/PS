#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	lld a, b;
	scanf("%lld %lld", &a, &b);
	vector<bool> v(b - a + 1, false);

	for (lld x = 2; x*x <= b; ++x) {
		lld x2 = x*x;
		for (lld y = a / x2 * x2; y <= b; y += x2) {
			if (y < a) continue;
			v[y - a] = true;
		}
	}

	lld ans = 0;
	for (lld i = a; i <= b; ++i) ans += v[i - a];
	printf("%lld\n", b - a + 1 - ans);
	return 0;
}