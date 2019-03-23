#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

vector<int> adj[700];
int cap[700][700];
bool visit[700];

int dfs(int cur, int sink, int flow) {
    if (visit[cur]) return 0;
    visit[cur] = true;

    if (cur == sink) return flow;

    for (int i = 0; i < adj[cur].size(); ++i) {
        int next = adj[cur][i];
        if (cap[cur][next] > 0) {
            int f = dfs(next, sink, min(flow, cap[cur][next]));
            if (f != 0) {
                cap[cur][next] -= f;
                cap[next][cur] += f;
                return f;
            }
        }
    }
    return 0;
}

int solve(int src, int sink) {
    int ans = 0, f;
    do {
        memset(visit, false, sizeof(visit));
        f = dfs(src, sink, INF);
        ans += f;
    } while (f);
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int src = 0, sink = n + m + 1;
    for (int i = 1; i <= n; ++i) {
        int k, x;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            int j = n + x;
            adj[i].push_back(j);
            adj[j].push_back(i);
            cap[i][j] += 1;
        }
        adj[src].push_back(i);
        cap[src][i] += 1;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        adj[i].push_back(sink);
        cap[i][sink] += 1;
    }

    printf("%d\n", solve(src, sink));

    return 0;
}