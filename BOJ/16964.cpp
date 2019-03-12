#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n;
vector<int> adj[MAX_N + 1];
int level[MAX_N + 1];
int tsize[MAX_N + 1];
bool visit[MAX_N + 1];

int dfs(int x, int lv = 0) {
    if (visit[x]) return 0;
    visit[x] = true;

    int size = 1;
    level[x] = lv;
    for (int i = 0; i < adj[x].size(); ++i) {
        int next = adj[x][i];
        size += dfs(next, lv + 1);
    }
    return tsize[x] = size;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int s, e;
        scanf("%d %d", &s, &e);
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    dfs(0);

    int order[MAX_N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &order[i]);
        order[i]--;
    }

    if (order[0] != 0) return puts("0"), 0;

    for (int i = 1; i < n; ++i) {
        int x = order[i];
        if (tsize[x] == 1 || i + tsize[x] >= n) continue;
        int next = order[i + tsize[x]];
        if (level[next] > level[x]) {
            return puts("0"), 0;
        }
    }
    puts("1");

    return 0;
}