#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>
#include <tuple>
using namespace std;

typedef long long lld;

#define INF 987654321
#define MOD 1000000007

typedef pair<int, int> ii;

int main() {
	int n;
	scanf("%d", &n);

	vector<lld> sq(n+1);
	sq[0] = 1;
	for (int i = 1; i <= n; ++i) {
		sq[i] = (sq[i - 1] * 2) % MOD;
	}

	vector<lld> a(n);
	for (auto& x : a) scanf("%lld", &x);
	sort(a.begin(), a.end());

	lld ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + (a[i] * (sq[i] - 1)) % MOD) % MOD;
		ans = (ans - (a[i] * (sq[n - 1 - i] - 1)) % MOD + MOD) % MOD;
	}
	printf("%lld", ans);

	return 0;
}