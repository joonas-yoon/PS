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
#include <map>
using namespace std;

typedef long long lld;

#define INF 987654321

typedef pair<int, int> ii;

bool connectable(const string& s, const string& p) {
	if (s.size() != p.size() ) return false;
	int d = 0;
	for (int i = 0; i < s.size(); ++i) {
		d += s[i] != p[i];
		if (d >= 2) break;
	}
	return d <= 1;
}

vector<int> adj[20001];
bool visit[20001];

bool dfs(int cur, const int& e) {
	if (cur == e) return true;
	if (visit[cur]) return false;
	visit[cur] = true;
	for (auto& next : adj[cur]) {
		if (dfs(next, e)) return true;
	}
	return false;
}

int main() {
	vector<string> str;
	map<string, int> index;
	char s[4096];
	for (int i = 0; ~scanf("%s ", s); ++i) {
		if (s[0] == '-') break;
		index[s] = i;
		str.push_back(s);
	}

	int n = str.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (connectable(str[i], str[j])) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	char p[4096];
	while (~scanf("%s %s ", s, p) ){
		memset(visit, false, sizeof(visit));
		if (index.count(s) == 0 || index.count(p) == 0) puts("No");
		else puts( dfs(index[s], index[p]) ? "Yes" : "No");
	}

	return 0;
}