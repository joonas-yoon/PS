#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>2)

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

#define MOD 1000000

int main() {
	vector<int> x(1000001);
	x[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		x[i] = (x[i] + x[(int)(i - sqrt(i) + 1e-12)]) % MOD;
		x[i] = (x[i] + x[(int)log10(i)]) % MOD;
		x[i] = (x[i] + x[(int)(sin(i)*sin(i)*i)]) % MOD;
	}

	int n;
	while (~scanf("%d", &n) && n != -1) {
		printf("%d\n", x[n]);
	}

	return 0;
}