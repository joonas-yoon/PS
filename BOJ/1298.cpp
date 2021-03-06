#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> adj[205];
int cap[205][205];
bool visit[205];

int dfs(int src, int sink, int flow) {
    if (visit[src]) return 0;
    visit[src] = true;

    if (src == sink) return flow;

    for (int i = 0; i < adj[src].size(); ++i) {
        int next = adj[src][i];
        if (cap[src][next] > 0) {
            int f = dfs(next, sink, min(flow, cap[src][next]));
            if (f > 0) {
                cap[src][next] -= f;
                cap[next][src] += f;
                return f;
            }
        }
    }
    return 0;
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
        cap[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
        cap[n + i][sink] = 1;
        adj[n + i].push_back(sink);
        adj[sink].push_back(n + i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visit, false, sizeof(visit));
        ans += dfs(i, sink, INF);
    }
    printf("%d\n", ans);

    return 0;
}