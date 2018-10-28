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

int main(){
    fastio();

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int food[10][10];
	FOR(i, n) FOR(j, n) scanf("%d", &food[i][j]);

	vector<vector<int>> w(n, vector<int>(n, 5));

	vector<int> tree[10][10];
	while (m--) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		tree[x - 1][y - 1].push_back(age);
	}

	while(k--){
		int dead[10][10] = {};

		vector<ii> blossom;

		FOR(i, n) {
			FOR(j, n) {
				vector<int> tmp;
				sort(all(tree[i][j]));
				for (auto& age : tree[i][j]) {
					if (w[i][j] - age >= 0) {
						w[i][j] -= age;
						tmp.push_back(age + 1);

						if ((age + 1) % 5 == 0) {
							blossom.push_back({i, j});
						}
					} else {
						dead[i][j] += age / 2;
					}
				}
				tree[i][j] = tmp;
			}
		}

		for (auto& b : blossom) {
			int y = b.first, x = b.second;
			FOR(d, 8) {
				int ny = y + dy[d], nx = x + dx[d];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				tree[ny][nx].push_back(1);
			}
		}

		FOR(i, n) {
			FOR(j, n) {
				w[i][j] += dead[i][j] + food[i][j];
			}
		}
	}

	int sum = 0;
	FOR(i, n) FOR(j, n) sum += tree[i][j].size();
	printf("%d\n", sum);

	return 0;
}