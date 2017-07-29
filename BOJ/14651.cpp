#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long lld;

const lld mod = 1e9+9;

int main() {
	int n;
	scanf("%d", &n);

	lld tri[50001]={};
	tri[0] = 1;
	for(int i=1; i<=50000; ++i){
		tri[i] = (tri[i-1] * 3) % mod;
	}

	lld dp[50001] = {};
	dp[2] = 2;
	for (int i = 3; i <= 50000; ++i) {
		dp[i] = 2 * (dp[i - 1] + tri[i - 3]) % mod;
	}

	printf("%lld", dp[n]);
	return 0;
}