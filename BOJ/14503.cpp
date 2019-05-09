#include <bits/stdc++.h>
using namespace std;

static int dy[] = {-1,0,1,0};
static int dx[] = {0,1,0,-1};

int h, w;
bool clean[50][50];
int g[51][51];

bool safe(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w && g[y][x] != 1;
}

int main() {
    int y, x, d;
    scanf("%d %d %d %d %d", &h, &w, &y, &x, &d);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &g[i][j]);
        }
    }

    while (safe(y, x)) {
        clean[y][x] = true;

        int ny, nx, nd = -1;
        for (int i = 1; i <= 4; ++i) {
            int j = (d + 4 - i) % 4;
            ny = y + dy[j];
            nx = x + dx[j];
            if (safe(ny, nx) && !clean[ny][nx]) {
                nd = j;
                break;
            }
        }

        if (nd != -1) {
            y = ny, x = nx, d = nd;
            continue;
        }

        // 후진
        int back = (d + 2) % 4;
        y += dy[back];
        x += dx[back];
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans += clean[i][j];
        }
    }
    printf("%d\n", ans);

    return 0;
}