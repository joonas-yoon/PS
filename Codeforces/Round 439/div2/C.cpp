#include <cstdio>

using lld = long long;

#define MAX 5000
#define MOD 998244353

int C[MAX + 1][MAX + 1]; // C[n][r]
int P[MAX + 1][MAX + 1]; // P[n][r]

void calcBino() {
	for (int i = 0; i <= MAX; i++) {
		C[i][0] = P[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			P[i][j] = ((i - j + 1LL) * P[i][j - 1]) % MOD;
		}
	}
}

lld solve(int a, int b, int c) {
	lld ra = 0, rb = 0, rc = 0;
	for (int i = 0; i <= a; ++i)
		ra = (ra + ((lld)C[a][i] * P[b][i]) % MOD) % MOD;
	for (int i = 0; i <= b; ++i)
		rb = (rb + ((lld)C[b][i] * P[c][i]) % MOD) % MOD;
	for (int i = 0; i <= c; ++i)
		rc = (rc + ((lld)C[c][i] * P[a][i]) % MOD) % MOD;
	return (rc * ((ra * rb) % MOD)) % MOD;
}

int main() {
	calcBino();
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld\n", solve(a, b, c));
	return 0;
}