#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios_base::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 9;
const double EPS = 1e-12;

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,1,-1};

bool v[20][20][1 << 10];

struct state {
    int y, x, bit;
};

int main() {
    int h, w;
    while (~scanf("%d %d", &w, &h) && h && w) {
        memset(v, false, sizeof(v));

        char g[20][21] = {};

        int stuffs = 0;
        queue<state> q;
        for (int i = 0; i < h; ++i) {
            scanf("%s ", g[i]);
            for (int j = 0; j < w; ++j) {
                if (g[i][j] == '*') g[i][j] = 'A' + (stuffs++);
                if (g[i][j] == 'o') {
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

                if (b == (1 << stuffs) - 1) {
                    find = true;
                    break;
                }

                for (int i = 0; i < 4; ++i) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

                    char ch = g[ny][nx];
                    int nb = b;
                    if ('A' <= ch && ch <= 'K') {
                        nb = b | (1 << (ch - 'A'));
                    }
                    if (ch == 'x' || v[ny][nx][nb]) continue;
                    v[ny][nx][nb] = true;
                    q.push({ny, nx, nb});
                }
            }
            if (find) break;
            ++ans;
        }

        printf("%d\n", find ? ans : -1);
    }

    return 0;
}