#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int main() {
	int n, src, dst, front, back, k;
	scanf("%d %d %d %d %d %d", &n, &src, &dst, &front, &back, &k);
	bool caps[100001] = {};
	for (int i = 0, x; i < k; ++i) {
		scanf("%d", &x);
		caps[x] = true;
	}
	int dist = 0, d[100001];
	for (int i = 0; i <= n; ++i) d[i] = INF;
	bool find = false;
	queue<int> q;
	q.push(src);
	d[src] = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();
			if (cur == dst) {
				find = true;
				break;
			}
			int nd[2] = { -back, +front };
			for (int i = 0; i < 2; ++i) {
				int next = cur + nd[i];
				if (next < 1 || next > n || caps[next] || dist + 1 >= d[next]) continue;
				d[next] = dist + 1;
				q.push(next);
			}
		}
		if (find) break;
		++dist;
	}
	if (!find) puts("BUG FOUND");
	else printf("%d\n", dist);
	return 0;
}