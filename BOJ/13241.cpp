#include <cstdio>

using lld = long long;

lld gcd(lld p, lld q) { return q ? gcd(q, p%q) : p; }

int main(){
	lld a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a / gcd(a, b) * b);
	return 0;
}