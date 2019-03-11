#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    bool g[100][100] = {};
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x - 1][y - 1] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (!g[i][k]) continue;
            for (int j = 0; j < n; ++j)
                g[i][j] |= g[i][k] & g[k][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            cnt += i == j || g[i][j] || g[j][i];
        printf("%d\n", n - cnt);
    }
    return 0;
}