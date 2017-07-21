#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

void tracking(vector<int>& p, int cur) {
	if (p[cur] != -1) {
		tracking(p, p[cur]);
	}
	printf("%d ", cur);
}

int main() {
	int n, k, MAX = 100002;
	scanf("%d %d", &n, &k);

	queue<int> q;
	vector<int> d(MAX, INF);
	vector<int> prev(MAX, -1);
	q.push(n);
	d[n] = 0;
	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int c = q.front();
			q.pop();

			if (c == k) continue;

			int next[] = { c - 1, c + 1, 2 * c };
			for (int i = 0; i < 3; ++i) {
				int nc = next[i];
				if (nc < 0 || nc >= MAX) continue;

				if (d[nc] > dist + 1) {
					prev[nc] = c;
					d[nc] = dist + 1;
					q.push(nc);
				}
			}
		}
		++dist;
	}
	printf("%d\n", d[k]);
	tracking(prev, k);
	return 0;
}