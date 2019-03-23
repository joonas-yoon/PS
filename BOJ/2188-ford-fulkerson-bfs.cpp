#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

vector<int> adj[500];
int cap[500][500];
int flow[500][500];

int bfs(int n, int src, int sink) {
    vector<int> from(n, -1);
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == sink) break;

        for (auto& next : adj[cur]) {
            if (cap[cur][next] - flow[cur][next] > 0 && from[next] == -1) {
                q.push(next);
                from[next] = cur;
            }
        }
    }

    if (from[sink] == -1) return 0;

    int f = 1;
    for (int i = sink; i != src; i = from[i]) f = min(f, cap[from[i]][i] - flow[from[i]][i]);
    for (int i = sink; i != src; i = from[i]) {
        flow[from[i]][i] += f;
        flow[i][from[i]] -= f;
    }
    return f;
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

    int ans = 0, nodes = n + m + 2;
    for (int i = 1; i <= n; ++i)
        ans += bfs(nodes, i, sink);
    printf("%d\n", ans);

    return 0;
}