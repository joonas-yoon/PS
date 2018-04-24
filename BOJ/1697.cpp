#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	const int MAX_N = max(n, k) * 2 + 1;
	vector<int> d(MAX_N, INF);

	queue<int> q;
	q.push(n);
	int dist = 0;
	d[n] = 0;
	while (!q.empty()) {
		int qs = q.size();
		bool find = false;
		while (qs--) {
			int x = q.front();
			q.pop();

			if (x == k) {
				find = true;
				break;
			}

			int next[3] = { x - 1, x + 1, 2 * x };
			for (int i = 0; i < 3; ++i) {
				int nx = next[i];
				if (nx < 0 || nx >= MAX_N || d[x] + 1 >= d[nx]) continue;
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
		if (find) break;
		++dist;
	}

	printf("%d\n", d[k]);

	return 0;
}