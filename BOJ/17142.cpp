#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()
#define FOR(i,n) for(int i=0;i<n;++i)

typedef pair<int, int> ii;

const int INF = 0x3F3F3F3F;

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,1,-1};

int g[51][51];
bool vis[51][51];

int bfs(int n, queue<ii>& q) {
    int rest = 0;
    FOR(i, n) FOR(j, n) {
        rest += g[i][j] == 0;
    }

    int ans = 0;
    while (!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            rest -= g[y][x] == 0;
            if (rest == 0) return ans;

            FOR(i, 4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (vis[ny][nx] || g[ny][nx] == 1) continue;
                q.push({ny, nx});
                vis[ny][nx] = true;
            }
        }
        ++ans;
    }

    return INF;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<ii> spot;
    FOR(i, n) FOR(j, n) {
        scanf("%d", &g[i][j]);
        if (g[i][j] == 2) spot.push_back({i, j});
    }

    vector<int> choice(spot.size(), 0);
    FOR(i, m) choice[spot.size() - 1 - i] = true;

    int ans = INF;
    do {
        queue<ii> q;
        memset(vis, false, sizeof(vis));
        FOR(i, spot.size()) {
            if (choice[i]) {
                q.push(spot[i]);
                vis[spot[i].first][spot[i].second] = true;
           }
        }
        ans = min(ans, bfs(n, q));
    } while (next_permutation(all(choice)));

    printf("%d\n", ans < INF ? ans : -1);

    return 0;
}