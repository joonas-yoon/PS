#include <cstdio>

int main() {
    int f[32], g[32];
    f[0] = g[1] = 1;
    f[1] = g[0] = 0;
    for (int n = 2; n <= 30; ++n) {
        f[n] = 2 * g[n - 1] + f[n - 2];
        g[n] = f[n - 1] + g[n - 2];
    }
    int n;
    while (~scanf("%d", &n) && n >= 0) printf("%d\n", f[n]);
    return 0;
}