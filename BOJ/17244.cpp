#include <bits/stdc++.h>
using namespace std;

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,1,-1};

bool v[50][50][1 << 5];
char g[50][51];

struct state {
    int y, x, bit;
};

int main() {
    int h, w;
    scanf("%d %d", &w, &h);

    int stuffs = 0;
    queue<state> q;
    for (int i=0; i < h; ++i) {
        scanf("%s ", g[i]);
        for (int j=0; j < w; ++j) {
            char& ch = g[i][j];
            if (ch == 'X') ch = '0' + (stuffs++);
            if (ch == 'S') {
                q.push({i, j, 0});
                v[i][j][0] = true;
            }
        }
    }

    int ans = 0;
    bool find = false;
    while (!q.empty()) {
        int qs = q.size();
        find = false;
        while (qs--) {
            int y = q.front().y;
            int x = q.front().x;
            int b = q.front().bit;
            q.pop();

            if (b == (1 << stuffs) - 1 && g[y][x] == 'E') {
                find = true;
                break;
            }

            for (int i=0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

                char ch = g[ny][nx];
                int nb = b;
                if ('0' <= ch && ch <= '9') {
                    nb = b | (1 << (ch - '0'));
                }
                if (ch == '#' || v[ny][nx][nb]) continue;
                v[ny][nx][nb] = true;
                q.push({ny, nx, nb});
            }
        }
        if (find) break;
        ++ans;
    }

    printf("%d\n", ans);

    return 0;
}