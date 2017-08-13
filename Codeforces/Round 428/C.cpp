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

static int dy[] = { -1,1,0,0 };	
static int dx[] = { 0,0,-1,1 };

vector<int> adj[100001];

double solve(int cur, int prev) {
	double ret = 0;
	int sz = (int)adj[cur].size() - (cur != 1);
	for (auto& next : adj[cur]) {
		if (next != prev)
			ret += (1 + solve(next, cur)) / (1e-12 + sz);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int s, e, i = 1; i < n; ++i) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	printf("%.10lf", solve(1, -1));
	return 0;
}