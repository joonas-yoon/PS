#include <bits/stdc++.h>
using namespace std;

int n, parent[52];
vector<int> adj[52];

int dfs(int cur) {
    if (adj[cur].empty()) return cur != 0;

    int cnt = 0;
    for (int i = 0; i < adj[cur].size(); ++i) {
        cnt += dfs(adj[cur][i]);
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        x += 1;
        parent[i] = x;
        adj[x].push_back(i);
    }

    int x;
    scanf("%d", &x);
    x += 1;
    int p = parent[x];
    for (auto i = adj[p].begin(); i != adj[p].end();) {
        if (*i == x) {
            i = adj[p].erase(i);
        } else {
            i++;
        }
    }

    printf("%d\n", dfs(0));

    return 0;
}