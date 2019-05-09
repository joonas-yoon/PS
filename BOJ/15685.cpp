#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = { 1, 0, -1, 0 };
static int dy[] = { 0, -1, 0, 1 };

int grid[111][111];

void paint(int x, int y) {
    for (int d = 0; d < 4; ++d) {
        grid[y + (d / 2)][x + (d % 2)] |= 1 << d;
    }
}

bool isPainted(int x, int y) {
    return grid[y][x] == 15;
}

int main() {
    vector<int> dragon(1, 0);
    for (int i = 0; i <= 10; ++i) {
        for (int j = (int)dragon.size() - 1; j >= 0; --j)
            dragon.push_back((dragon[j] + 1) % 4);
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        int gen_size = 1 << g;
        for (int i = 0; i <= gen_size; ++i) {
            paint(x, y);
            if (i == gen_size) break;
            int nd = (dragon[i] + d) % 4;
            x += dx[nd];
            y += dy[nd];
        }
    }

    int ans = 0;
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 105; ++j)
            ans += isPainted(j, i);
    printf("%d\n", ans);

    return 0;
}