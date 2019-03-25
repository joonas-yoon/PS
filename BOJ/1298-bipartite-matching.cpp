#include <bits/stdc++.h>
using namespace std;

vector<int> adj[205];
bool cap[205][205];
bool visit[205];

bool dfs(int src, int sink) {
    if (visit[src]) return false;
    visit[src] = true;

    if (src == sink) return true;

    for (auto& next : adj[src]) {
        if (cap[src][next]) {
            bool res = dfs(next, sink);
            if (res) {
                cap[src][next] = false;
                cap[next][src] = true;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int sink = 2 * n + 1;
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        e += n;
        cap[s][e] = 1;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= n; ++i) {
        cap[n + i][sink] = 1;
        adj[n + i].push_back(sink);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visit, false, sizeof(visit));
        ans += dfs(i, sink);
    }
    printf("%d\n", ans);

    return 0;
}