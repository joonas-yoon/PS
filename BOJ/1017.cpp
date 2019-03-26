#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<(n); ++i)
#define all(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;

vector<int> adj[51];
bool visit[51];
int pred[51];

bool solve(int x) {
    if (x == -1) return true;
    for (int i = 0; i < adj[x].size(); ++i) {
        int next = adj[x][i];
        if (visit[next]) continue;
        visit[next] = true;
        if (solve(pred[next])) {
            pred[next] = x;
            return true;
        }
    }
    return false;
}

bool era[2500];

int main() {
    era[0] = era[1] = true;
    for (int i = 2; i < 2500; ++i) {
        if (era[i]) continue;
        for (int j = i * i; j < 2500; j += i) era[j] = true;
    }

    int n;
    scanf("%d", &n);
    vector<int> a, b;
    for (int x, i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (i == 0 || a[0] % 2 == x % 2) a.push_back(x);
        else b.push_back(x);
    }

    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (era[a[i] + b[j]]) continue;
            adj[i].push_back(j);
        }
    }

    vector<int> res;
    for (int i = 0; i < b.size(); ++i) {
        if (era[a[0] + b[i]]) continue;

        adj[0].push_back(i);
        memset(pred, -1, sizeof(pred));
        int ans = 0;
        for (int j = 0; j < a.size(); ++j) {
            memset(visit, false, sizeof(visit));
            ans += solve(j);
        }
        adj[0].clear();

        if (ans == n / 2) res.push_back(b[i]);
    }

    if (res.empty()) return puts("-1"), 0;

    sort(all(res));
    for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);

    return 0;
}