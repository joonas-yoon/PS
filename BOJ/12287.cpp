#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

vector<int> adj[201];

int color[201];

bool isBipartite(int cur, int c) {
	if (color[cur] == !c) return false;
	if (color[cur] != -1) return true;

	color[cur] = c;
	for (auto& next : adj[cur]) {
		if (isBipartite(next, !c) == false) {
			return false;
		}
	}
	return true;
}

int main() {
	fastio();
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(color, -1, sizeof(color));
		for (int i = 0; i < 201; ++i) adj[i].clear();

		int m;
		cin >> m;
		string s1, s2;
		map<string, int> idx;
		for (int i = 0; i < m; ++i) {
			cin >> s1 >> s2;
			if (idx.find(s1) == idx.end()) idx[s1] = idx.size();
			if (idx.find(s2) == idx.end()) idx[s2] = idx.size();
			adj[idx[s1]].push_back(idx[s2]);
			adj[idx[s2]].push_back(idx[s1]);
		}

		bool answer = true;
		for (auto& cur : idx) {
			int x = cur.second;
			if (color[x] != -1) answer &= isBipartite(x, color[x]);
			else answer &= isBipartite(x, 0);
		}
		printf("Case #%d: %s\n", tc, answer ? "Yes" : "No");
	}
	return 0;
}