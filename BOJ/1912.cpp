#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#define gets(s) gets_s(s)
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

int n, a[100005];
int dp[100005][2];

int solve(int cur, bool cont = false) {
	if (cur >= n) return 0;
	int& ret = dp[cur][cont];
	if (ret != -INF) return ret;

	ret = 0;
	if (!cont) ret = max(ret, solve(cur + 1, false));
	ret = max(ret, a[cur] + solve(cur + 1, true));
	return ret;
}


int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", &a[i]);
	FOR(i, n) FOR(j, 2) dp[i][j] = -INF;
	int ans = solve(0);
	printf("%d\n", ans <= 0 ? *max_element(a, a+n) : ans);
	return 0;
}