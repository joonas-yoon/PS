#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int main() {
	int n, k, MAX = 100002;
	scanf("%d %d", &n, &k);

	queue<ii> q;
	vector<int> d(MAX, INF);
	q.push({ n, 0 });
	d[n] = 0;
	while (!q.empty()) {
		ii c = q.front();
		q.pop();

		int next[] = { c.first - 1, c.first + 1, 2 * c.first };
		for (int i = 0; i < 3; ++i) {
			int nc = next[i], nd = i != 2;
			if (nc < 0 || nc >= MAX) continue;

			if (d[nc] > c.second + nd) {
				d[nc] = c.second + nd;
				q.push({ nc, c.second + nd });
			}
		}
	}
	printf("%d", d[k]);
	return 0;
}