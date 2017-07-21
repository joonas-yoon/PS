#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n, k, MAX = 100001;
	scanf("%d %d", &n, &k);

	queue<int> q;
	vector<int> d(MAX, INF);
	vector<int> times(MAX, 0);
	q.push(n);
	d[n] = 0;
	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int c = q.front();
			q.pop();

			if (c == k && dist == d[c]) times[dist]++;

			int next[] = { c - 1, c + 1, 2 * c };
			for (int i = 0; i < 3; ++i) {
				int nc = next[i];
				if (nc < 0 || nc >= MAX) continue;

				if (dist + 1 <= d[nc]) {
					d[nc] = dist + 1;
					q.push(nc);
				}
			}
		}
		++dist;
	}
	printf("%d %d", d[k], times[d[k]]);
	return 0;
}