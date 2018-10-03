#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld f(int n) {
	if (n <= 0) return 0;
	lld ans = 0, sum = 0;
	int x = (n + 1) % 2;
	for (lld i = 1; i <= n; ++i) {
		sum += i;
		ans += sum * (i % 2 == x ? 2 : 1);
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", f(n));
	return 0;
}