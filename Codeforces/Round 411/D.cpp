#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <set>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>1)

#define MOD 1000000007

typedef pair<int, int> ii;

lld two[1000001]; // 2^k % mod

lld solve(int i, int j) {
	return ((two[i] - 1) * (j % MOD)) % MOD;
}

int main() {
	two[0] = 1LL;
	for (int i = 1; i < 1000001; ++i) {
		two[i] = (two[i - 1] * 2LL) % MOD;
	}

	char s[1000001];
	scanf("%s", &s);
	int i = 0, len = strlen(s);
	lld ans = 0;
	int a = 0;
	while(i < len){
		int b = 0;
		while (i < len && s[i] == 'a') a++, i++;
		while (i < len && s[i] == 'b') b++, i++;
		ans = (ans + solve(a, b)) % MOD;
	}
	printf("%lld", ans);

	return 0;
}