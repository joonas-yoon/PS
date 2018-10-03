#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld gcd(lld p, lld q) {
	return q ? gcd(q, p%q) : p;
}

int main() {
	lld A, B, C, N, a, b, i, d, r;
    scanf("%lld %lld %lld", &A, &B, &C);

	A *= B;
	B = C;
	printf("%lld.", A / B);

	r = gcd(A, B);
	b = B / r;
	a = A / r % b;
	for (i = 0, d = 1, r = a; i < 10; ++i) {
		d = 10 * r / b;
		r = 10 * r % b;
		printf("%1d", d);
	}
	return 0;
}