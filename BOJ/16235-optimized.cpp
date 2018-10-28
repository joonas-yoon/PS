#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int food[10][10];
	FOR(i, n) FOR(j, n) scanf("%d", &food[i][j]);

	vector<vector<int>> w(n, vector<int>(n, 5));

	list<ii> tree[10][10];
	while (m--) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		tree[x - 1][y - 1].push_back({age, 1});
	}

	while (k--) {
		int blossom[10][10] = {};

		FOR(i, n) {
			FOR(j, n) {
				int poo = 0;
				for (auto& tr : tree[i][j]) {
					int& age = tr.first;	// 나이가 age인
					int& cnt = tr.second;	// 나무의 수 cnt

					int alive = min(w[i][j] / age, cnt);
					w[i][j] -= (lld)alive * age;
					poo += (age / 2) * (cnt - alive);

					age += 1;
					cnt = alive;
					if (age % 5 == 0) {
						blossom[i][j] += cnt;
					}
				}
				w[i][j] += poo;
				while (!tree[i][j].empty() && tree[i][j].back().second == 0) {
					tree[i][j].pop_back();
				}
			}
		}

		FOR(i, n) {
			FOR(j, n) {
				// 주변으로부터 이 곳으로 번식되는 나무 수
				int cnt = 0;
				FOR(d, 8) {
					int nx = i + dx[d], ny = j + dy[d];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					cnt += blossom[nx][ny];
				}
				if (cnt > 0) {
					tree[i][j].push_front({1, cnt});
				}
				w[i][j] += food[i][j];
			}
		}
	}

	int sum = 0;
	FOR(i, n) {
		FOR(j, n) {
			for (auto& x : tree[i][j])
				sum += x.second;
		}
	}
	printf("%d\n", sum);

	return 0;
}