#include <bits/stdc++.h>
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

	priority_queue<ii> q;
	vector<int> d(MAX, INF);
	q.push({ 0, n });
	d[n] = 0;
	while (!q.empty()) {
		ii c = q.top();
		q.pop();

		if (c.second == k) break;

		int next[] = { c.second- 1, c.second + 1, 2 * c.second };
		for (int i = 0; i < 3; ++i) {
			int nc = next[i], nd = i != 2;
			if (nc < 0 || nc >= MAX) continue;

			int next_d = -c.first + nd;
			if (d[nc] > next_d) {
				d[nc] = next_d;
				q.push({ -next_d, nc });
			}
		}
	}
	printf("%d", d[k]);
	return 0;
}