#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

const lld MOD = 1e9 + 7;

// a ^ p
lld fastPow(int a, int p) {
	if (p == 0) return 1;
	if (p & 1) return ((a % MOD) * fastPow(a, p - 1)) % MOD;
	lld r = fastPow(a, p / 2) % MOD;
	return (r * r) % MOD;
}

// n C m (mod p)
lld nCm(int n, int m, int p){
	lld num = 1, dem = 1;
	for (int i = 1; i <= m; ++i) {
		num = num * (n - i + 1) % p;
		dem = dem * i % p;
	}

	// http://koosaga.com/63
	// 페르마의 소정리에 의해서 a ^ (p - 1) == 1 (mod p) 이며, 이를 응용하면 a ^ (p - 2) == a ^ -1 (mod p)
	// 이것을 사용하면 mod p에서 나눗셈이 가능하다.

	// num / dem (mod p) == num * dem^-1 (mod p) = num * dem^(p-2) (mod p)

	return num * fastPow(dem, p - 2) % p;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld\n", nCm(n, k, MOD));

	return 0;
}