#include <cstdio>

int main() {
    int n, K;
    scanf("%d %d", &n, &K);
    bool g[401][401] = {};
    while (K--) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s - 1][e - 1] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (!g[i][k]) continue;
            for (int j = 0; j < n; ++j) {
                g[i][j] |= g[i][k] & g[k][j];
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int s, e;
        scanf("%d %d", &s, &e);
        if (g[s - 1][e - 1])
            puts("-1");
        else if (g[e - 1][s - 1])
            puts("1");
        else
            puts("0");
    }

    return 0;
}