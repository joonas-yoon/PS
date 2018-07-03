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

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { -1, 0, 1, 0 };

using point = ii;

int h, w;
char g[21][21];

// set up the traps on a, b and there are n-cities
int bfs(point a, point b, int n) {
	bool v[21][21] = {};
	queue<point> q;
	q.push(a); q.push(b);
	v[a.first][a.second] = v[b.first][b.second] = true;
	int dist = 0, cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			cnt += g[y][x] == '1';
			if (cnt == n) return dist;

			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d], nx = x + dx[d];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w || v[ny][nx]) continue;
				v[ny][nx] = true;
				q.push(point(ny, nx));
			}
		}

		++dist;
	}
	return 0;
}

int main() {
	scanf("%d %d ", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s ", g[i]);

	int cities = 0;
	FOR(y, h)
		FOR(x, w)
			cities += g[y][x] == '1';

	int ans = h * w;
	FOR(ay, h) FOR(ax, w) {
		FOR(by, h) FOR(bx, w) {
			point a(ay, ax), b(by, bx);
			if (a == b || g[ay][ax] != '0' || g[by][bx] != '0') continue;
			ans = min(ans, bfs(a, b, cities));
		}
	}
	printf("%d\n", ans);

	return 0;
}