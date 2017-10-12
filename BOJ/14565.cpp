#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld gcd(lld p, lld q) {
	return q ? gcd(q, p%q) : p;
}

void ee(lld a, lld b, lld &S, lld& T) {
	lld r[] = { a, b }, s[] = { 1, 0 }, t[] = { 0, 1 };
	while (r[1]) {
		lld q = r[0] / r[1];

		lld R = r[0] - q * r[1];
		r[0] = r[1], r[1] = R;

		S = s[0] - q * s[1];
		s[0] = s[1], s[1] = S;

		T = t[0] - q * t[1];
		t[0] = t[1], t[1] = T;
	}
	S = s[0], T = t[0];
}

// a*s = 1 (mod p)
// => a*s + p*t = 1
lld inverse_in_mod(lld a, lld p) {
	if (gcd(a, p) != 1) return -1;
	lld s, t; ee(a, p, s, t);
	return (s + p) % p;
}

int main() {
	lld n, a;
	while(~scanf("%lld %lld", &n, &a))
		printf("%lld %lld\n", n - a, inverse_in_mod(a, n));
	return 0;
}