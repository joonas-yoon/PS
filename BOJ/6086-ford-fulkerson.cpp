#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int id(char ch) {
    if (ch <= 'Z') return ch - 'A';
    return ch - 'a' + 26;
}

vector<int> adj[700];
int capacity[700][700];
bool visit[700];

int dfs(int u, int sink, int flow) {
    if (visit[u]) return 0;
    visit[u] = true;

    if (u == sink) return flow;

    // 모든 간선으로 흘려본다
    for (int i = 0; i < adj[u].size(); ++i) {
        int there = adj[u][i];
        if (capacity[u][there] > 0) {
            int f = dfs(there, sink, min(flow, capacity[u][there]));
            if (f > 0) {
                capacity[u][there] -= f; // f만큼 용량에 채운 효과
                capacity[there][u] += f;
                return f;
            }
        }
    }

    return 0;
}

// Ford-Fulkerson
int solve(int src, int sink) {
    int ans = 0, f = -1;
    do {
        // 흘려보낼수 있는 양이 0이면 종료
        memset(visit, false, sizeof(visit));
        f = dfs(src, sink, INF);
        ans += f;
    } while (f > 0);
    return ans;
}

int main() {
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        char a, b;
        int f;
        scanf("%c %c %d ", &a, &b, &f);
        int u = id(a), v = id(b);
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += f;
        capacity[v][u] += f;
    }

    int src = id('A'), sink = id('Z');
    printf("%d\n", solve(src, sink));
    return 0;
}