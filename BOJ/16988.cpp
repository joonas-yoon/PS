#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

static int dx[] = {0,0,1,-1};
static int dy[] = {1,-1,0,0};

#define ME  1
#define YOU 2

int h, w;
int grid[20][20];
bool vis[20][20];

void _set(ii& a, int val) {
    grid[a.first][a.second] = val;
}

int bfs(int sy, int sx) {
    int ans = 0;
    queue<ii> q;
    q.push(make_pair(sy, sx));
    vis[sy][sx] = true;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        ans++;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || vis[ny][nx]) continue;
            // 나가는 길이 있음
            if (grid[ny][nx] == 0) return 0;
            if (grid[ny][nx] == YOU) {
                q.push(make_pair(ny, nx));
                vis[ny][nx] = true;
            }
        }
    }
    return ans;
}

// 이 돌의 주변으로 탐색 시작
int solve(ii& a) {
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int y = a.first + dy[i];
        int x = a.second + dx[i];
        if (y < 0 || y >= h || x < 0 || x >= w || vis[y][x]) continue;
        if (grid[y][x] == YOU)
            ans += bfs(y, x);
    }
    return ans;
}

int main() {
    vector<ii> you, blank;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != 0) continue;
            int yours = 0;
            for (int k = 0; k < 4; ++k) {
                int y = i + dy[k], x = j + dx[k];
                if (y < 0 || y >= h || x < 0 || x >= w) continue;
                yours += grid[y][x] == YOU;
            }
            if (yours > 0) {
                blank.push_back(make_pair(i, j));
            }
        }
    }

    int ans = 0;
    int n = blank.size();
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            _set(blank[i], ME);
            _set(blank[j], ME);

            memset(vis, false, sizeof(vis));
            int cnt = solve(blank[i]) + solve(blank[j]);
            ans = max(ans, cnt);

            _set(blank[i], 0);
            _set(blank[j], 0);
        }
    }
    printf("%d\n", ans);

    return 0;
}