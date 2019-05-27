#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int g[200][200];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        g[a - 1][b - 1] = g[b - 1][a - 1] = k;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (i == k || g[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (i == j || j == k || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int ans = g[x - 1][y - 1] < INF ? g[x - 1][y - 1] : -1;
        printf("%d\n", ans);
    }

    return 0;
}