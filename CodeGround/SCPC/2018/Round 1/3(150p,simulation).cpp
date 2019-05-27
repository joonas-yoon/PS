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

vector<set<int>> g;

inline bool hasEdge(int u, int v) {
	return g[u].find(v) != g[u].end();
}

bool connected(int a, int x, int b) {
	return hasEdge(a, x) && hasEdge(b, x) && hasEdge(a, b);
}

int main() {
	fastio();

	int T;
	cin >> T;
	FOR(tc, T) {
		int v, e;
		cin >> v >> e;

		g.clear();
		g.resize(v);

		while (e--) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].insert(v);
			g[v].insert(u);
		}

		bool change;
		do {
			change = false;
			for (int x = 0; x < v; ++x) {
				if (g[x].size() != 2) continue;

				vector<int> t(all(g[x]));
				int a = t[0], b = t[1];
				if (connected(a, x, b)) {
					change = true;
					g[a].erase(x);
					g[b].erase(x);
					g[x].clear();
				}
			}
		} while (change);

		int ans = 0;
		for (auto& x : g) ans += !x.empty();
		cout << "Case #" << tc + 1 << '\n';
		cout << ans << '\n';
	}

	return 0;
}