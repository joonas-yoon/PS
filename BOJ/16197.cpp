#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
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

typedef pair<ii, ii> balls;

int h, w;

bool isIn(ii& ball) {
	int y = ball.first;
	int x = ball.second;
	return 0 <= x && x < w && 0 <= y && y < h;
}

ii nextBall(ii& ball, int d) {
	return make_pair(ball.first + dy[d], ball.second + dx[d]);
}

int main() {
	scanf("%d %d", &h, &w);
	char s[21][21];
	vector<ii> v;
	FOR(i, h) {
		scanf("%s ", s[i]);
		FOR(j, w) {
			if (s[i][j] == 'o') v.push_back({ i, j });
		}
	}

	bool vis[21][21][21][21] = {};
	queue<balls> q;
	q.push(make_pair(v[0], v[1]));
	vis[v[0].first][v[0].second][v[1].first][v[1].second] = true;

	int dist = 0;
	while (!q.empty() && dist <= 10) {
		int qs = q.size();
		bool find = false;
		while (qs--) {
			ii b1 = q.front().first;
			ii b2 = q.front().second;
			q.pop();

			if (isIn(b1) != isIn(b2)) {
				printf("%d\n", dist);
				return 0;
			}
			else if (isIn(b1) == false) {
				continue;
			}

			FOR(d, 4) {
				ii nb1 = nextBall(b1, d);
				if (isIn(nb1) && s[nb1.first][nb1.second] == '#') {
					nb1 = b1;
				}
				ii nb2 = nextBall(b2, d);
				if (isIn(nb2) && s[nb2.first][nb2.second] == '#') {
					nb2 = b2;
				}

				if (vis[nb1.first][nb1.second][nb2.first][nb2.second]) continue;
				vis[nb1.first][nb1.second][nb2.first][nb2.second] = true;
				q.push(make_pair(nb1, nb2));
			}
		}
		if (find) break;
		dist++;
	}
	puts("-1");

	return 0;
}