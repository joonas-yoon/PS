#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
int g[10][10];
int shape[4][20];

int other(int a, int b) {
    static int x[] = {0,3,2,3,0,1,2,1,0};
    return x[(a - 1) * 3 + b - 1];
}

int winner(int a, int b, int result) {
    if (result == 2) return a;
    return result == 1 ? max(a, b) : b;
}

int calc(int score, int w) {
    static int x[] = {1,10,100};
    return score + x[w - 1];
}

// a번 사람 손
int getShape(int a, int bi, int ci) {
    return shape[a][a == 2 ? bi : ci];
}

void solve(int r, int score, int p, int q, int bi = 0, int ci = 0, int pool = 0) {
    if (score % 10 >= k) {
        puts("1");
        exit(0);
    }
    if (r >= 20 || score / 100 >= k || (score % 100) / 10 >= k) return;

    int v = other(p, q);
    int nbi = bi + (p == 2 || q == 2);
    int nci = ci + (p == 3 || q == 3);

    if (p == 1 || q == 1) {
        // 모양 하나씩 확인
        for (int x = 1; x <= n; ++x) {
            // 이미 있으면 패스
            if (pool & (1 << x)) continue;
            
            int w, f;
            if (p == 1)
                f = g[x][getShape(q, bi, ci)];
            else
                f = g[getShape(p, bi, ci)][x];
            w = winner(p, q, f);

            solve(r + 1, calc(score, w), w, v, nbi, nci, pool | (1 << x));
        }
    } else {
        int f = g[getShape(p, bi, ci)][getShape(q, bi, ci)];
        int w = winner(p, q, f);
        solve(r + 1, calc(score, w), w, v, nbi, nci, pool);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) scanf("%d ", &g[i][j]);
    }
    for (int i = 2; i < 4; ++i) {
        for (int r = 0; r < 20; ++r)
            scanf("%d", &shape[i][r]);
    }

    solve(0, 0, 1, 2);
    puts("0");

    return 0;
}