#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int fibo[101], dp[101];

// 가로 길이 n만큼을 좌우대칭으로 채울 수 있는 가짓 수
int g(int n) {
	if (n < 0) return 0;
	if (n < 3) return n < 2 ? 1 : 2;
	int& r = dp[n];
	if (r) return r;
	return r = (g(n - 2) + g(n - 4)) % MOD;
}

int main() {
	// 만들어지는 전체 가짓 수는 f(n) = f(n-1) + f(n-2) 이다.
	// 세로로 1칸을 차지하면 생기는 부분 문제 f(n-1)와, 가로로 2칸(=)을 차지하면 생기는 f(n-2).
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i <= 100; ++i) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", (fibo[n] - g(n) + MOD) % MOD);
	}
	return 0;
}