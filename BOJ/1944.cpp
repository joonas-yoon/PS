#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

struct edge {
	int u, v, w;
	bool operator < (const edge& e) const {
		return w < e.w;
	}
};

int find(vector<int>& r, int k) {
	if (k == r[k]) return k;
	return r[k] = find(r, r[k]);
}

bool merge(vector<int>& root, int p, int q) {
	if ((p = find(root, p)) == (q = find(root, q))) return false;
	root[q] = p;
	return true;
}

// [i][j]번째 칸은 k번 정점이다.
int id[50][50];
char maze[50][51];
int n, k;
int dist[251][251]; // 정점 i와 j 사이의 거리

bool isVertex(int y, int x) {
	return maze[y][x] == 'S' || maze[y][x] == 'K';
}

// 정점 (y, x)로부터 나머지 정점들에 대해 플러드 필
bool flood(int y, int x) {
	queue<ii> q;
	q.push({ y, x });
	int r = id[y][x], d = 0;
	bool vis[50][50] = {};
	vis[y][x] = true;
	int cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cy = q.front().first, cx = q.front().second;
			q.pop();

			if (isVertex(cy, cx)) {
				dist[r][id[cy][cx]] = d;
				if (++cnt >= k) return true;
			}

			for (int i = 0; i < 4; ++i) {
				int ny = cy + dy[i], nx = cx + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx] || maze[ny][nx] == '1') continue;
				vis[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
		++d;
	}
	return false;
}

int main() {
	memset(id, -1, sizeof(id));
	scanf("%d %d", &n, &k);
	FOR(i, n) scanf("%s ", maze[i]);
	k += 1; // include start
	vector<ii> key;
	FOR(i, n) {
		FOR(j, n) {
			dist[i][j] = INF;
			if (isVertex(i, j)) {
				id[i][j] = key.size();
				key.push_back({ i, j });
			}
		}
	}

	bool possible = false;
	FOR(i, n) 
		FOR(j, n) 
			if (isVertex(i, j))
				possible |= flood(i, j);
	if (!possible) return puts("-1"), 0;

	vector<edge> E;
	vector<int> group(k);
	FOR(i, k) {
		group[i] = i;
		REP(j, i + 1, k - 1) {
			int u = id[key[i].first][key[i].second];
			int v = id[key[j].first][key[j].second];
			E.push_back({ u, v, dist[u][v] });
		}
	}
	sort(all(E));
	
	// 시작점을 제외한 key끼리의 최소 거리 MST
	int ans = 0;
	for (auto& e : E)
		if (merge(group, e.u, e.v))
			ans += e.w;
	printf("%d\n", ans);

	return 0;
}