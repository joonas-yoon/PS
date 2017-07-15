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
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

vector<int> adj[2001];

int depth(vector<bool>& v, int cur, int dep = 1) {
	if (v[cur]) return 0;
	if (dep >= 5) return 1;
	v[cur] = true;
	int r = 0;
	for (auto& next : adj[cur]) {
		r = max(r, depth(v, next, dep + 1));
	}
	v[cur] = false;
	return r + 1;
}

bool solve(int n) {
	vector<bool> visit(n, false);
	for (int i = 0; i < n; ++i) {
		if (depth(visit, i) >= 5) return true;
	}
	return false;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (m < n-1) return puts("0"), 0;

	puts(solve(n) ? "1" : "0");

	return 0;
}