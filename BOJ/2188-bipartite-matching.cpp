#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> adj[205];
int pred[205]; // 오른쪽 노드가 sink로 간다면 -1, 아니라면 어디서 왔는 지
bool visit[205];

int dfs(int x) {
    if (x == -1) return true;
    for (int i = 0; i < adj[x].size(); ++i) {
        int next = adj[x][i];
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
    for (int i = 0; i < n; ++i) {
        int k, u;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &u);
            adj[i].push_back(u - 1);
        }
    }

    memset(pred, -1, sizeof(pred));

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        memset(visit, false, sizeof(visit));
        ans += dfs(i);
    }
    printf("%d\n", ans);

    return 0;
}