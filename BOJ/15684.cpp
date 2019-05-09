#include <bits/stdc++.h>
using namespace std;

int n, h;
bool g[30][10];
int chk[10];

bool canPut(int y, int x) {
    if (g[y][x] != false) return false;
    if (x > 0 && g[y][x - 1]) return false;
    if (x + 1 < n && g[y][x + 1]) return false;
    return true;
}

void solve(int pos, int sel , int limit) {
    if (sel == limit || pos >= (n - 1) * h) {
        for (int i = 0; i < n; ++i) chk[i] = i;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (g[i][j]) swap(chk[j], chk[j + 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (chk[i] != i) return;
        }
        printf("%d\n", limit);
        exit(0);
        return;
    }

    int r = pos / (n - 1);
    int c = pos % (n - 1);
    
    solve(pos + 1, sel, limit);
    if (canPut(r, c)) {
        g[r][c] = true;
        solve(pos + 1, sel + 1, limit);
        g[r][c] = false;
    }
}

int main() {
    int m;
    scanf("%d %d %d", &n, &m, &h);

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a - 1][b - 1] = true;
    }

    for (int i = 0; i < 4; ++i) solve(0, 0, i);
    puts("-1");

    return 0;
}