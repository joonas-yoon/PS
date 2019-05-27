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
#include <random>
#include <chrono>
#define gets(s) gets_s(s)
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { -1, 0, 1, 0 };

bool isPalin(int n) {
	char buf[10] = {};
	sprintf(buf, "%d", n);
	int len = strlen(buf);
	for (int l = 0, r = len - 1; l < r; l++, r--) {
		if (buf[l] != buf[r]) return false;
	}
	return true;
}

vector<int> palin;
vector<int> solve(int n) {
	vector<int> ans(4, 0);
	int pl = palin.size();
	FOR(i, pl) {
		if (palin[i] == n)
			return { palin[i] };

		if (ans.size() < 2) continue;

		REP(j, i, pl - 1) {
			if (palin[i] + palin[j] == n) {
				ans = { palin[i], palin[j] };
			}

			if (ans.size() < 3) continue;

			REP(k, j, pl - 1) {
				if (palin[i] + palin[j] + palin[k] == n) 
					ans = { palin[i], palin[j], palin[k] };
			}
		}
	}
	return ans;
}

int main() {
	fastio();

	for (int x = 9999; x > 0; --x) {
		if (isPalin(x)) palin.push_back(x);
	}

	int T;
	cin >> T;
	FOR(tc, T) {
		int n;
		cin >> n;

		vector<int> ans = solve(n);

		cout << "Case #" << tc + 1 << '\n';
		cout << ans.size() << ' ';
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}