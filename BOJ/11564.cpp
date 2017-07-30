#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	lld k, a, b;
	while (~scanf("%lld %lld %lld", &k, &a, &b)) {
		lld ans;
		if (a == b) ans = a % k == 0;
		else if (a <= 0 && 0 <= b) ans = -a / k + b / k + 1;
		else if (b < 0) ans = -a / k + (b + 1) / k;
        else ans = b / k - (a - 1) / k;
		printf("%lld\n", ans);
	}
	return 0;
}