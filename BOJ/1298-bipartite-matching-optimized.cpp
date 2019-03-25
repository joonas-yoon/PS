#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int pred[105]; // 오른쪽 노드가 sink로 간다면 -1, 아니라면 어디서 왔는 지
bool visit[105];

int dfs(int x) {
    if (x == -1) return true;
    for (auto& next : adj[x]) {
        if (visit[next]) continue;
        visit[next] = true;
        if (dfs(pred[next])) {
            pred[next] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
    }

    memset(pred, -1, sizeof(pred));

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visit, false, sizeof(visit));
        ans += dfs(i);
    }
    printf("%d\n", ans);

    return 0;
}