#include <cstdio>
#include <vector>
using namespace std;

const lld MOD = 1e9 + 7;

// a ^ p
lld fastPow(int a, int p) {
	if (p == 0) return 1;
	if (p & 1) return ((a % MOD) * fastPow(a, p - 1)) % MOD;
	lld r = fastPow(a, p / 2) % MOD;
	return (r * r) % MOD;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	lld num = 1, dem = 1;
	for (int i = 1; i <= k; ++i) {
		num = num * (n - i + 1) % MOD;
		dem = dem * i % MOD;
	}

	// http://koosaga.com/63
	// 페르마의 소정리에 의해서 a ^ (p - 1) == 1 (mod p) 이며, 이를 응용하면 a ^ (p - 2) == a ^ -1 (mod p)
	// 이것을 사용하면 mod p에서 나눗셈이 가능하다.

	// num / dem (mod p) == num * dem^-1 (mod p) = num * dem^(p-2) (mod p)

	printf("%lld", num * fastPow(dem, MOD - 2) % MOD);

	return 0;
}