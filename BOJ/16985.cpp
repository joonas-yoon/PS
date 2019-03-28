#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

static int dx[] = {-1,1,0,0,0,0};
static int dy[] = {0,0,1,-1,0,0};
static int dz[] = {0,0,0,0,1,-1};

int origin[5][5][5][4]; // [x][y][z][rotate]
int grid[5][5][5];

struct pos {
    int x, y, z;
};

int dr[5]; // 각 층의 방향
int order[] = {0,1,2,3,4};

int chk(int x, int y, int z) {
    return origin[order[x]][y][z][dr[x]];
}

int bfs() {
    if (chk(0, 0, 0) == 0 || chk(4, 4, 4) == 0) return INF;

    bool visit[5][5][5] = {};
    queue<pos> q;
    q.push({0, 0, 0});
    visit[order[0]][0][0] = true;

    int dist = 0;
    while (!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();

            if (x == 4 && y == 4 && z == 4) return dist;

            for (int i = 0; i < 6; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || nz < 0 || nz > 4) continue;
                if (visit[order[nx]][ny][nz] || chk(nx, ny, nz) == 0) continue;
                visit[order[nx]][ny][nz] = true;
                q.push({nx, ny, nz});
            }
        }
        ++dist;
    }
    return INF;
}

// k층을 r번 회전
int solve(int k, int r) {
    if (r > 3) return INF;
    if (k > 4) return bfs();
    dr[order[k]] = r;
    return min(solve(k, r + 1), solve(k + 1, 0));
}

int main() {
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%d", &grid[k][i][j]);
                origin[k][i][j][0] = grid[k][i][j];
            }
        }

        // 4방향 회전한 상태
        for (int r = 1; r < 4; ++r) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    origin[k][i][j][r] = origin[k][4-j][i][r-1];
                }
            }
        }
    }

    int ans = INF;
    do {
        ans = min(ans, solve(0, 0));
    } while (next_permutation(order, order + 5));

    printf("%d\n", ans < INF ? ans : -1);

    return 0;
}