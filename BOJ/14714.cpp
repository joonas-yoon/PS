#include <bits/stdc++.h>
using namespace std;

int n, a, b, da, db;

// [차례: A or B][A 지목권이 있는 위치][B 지목권이 있는 위치]
bool v[2][501][501];

struct ptr {
	int t, a, b, cnt;
};

int solve() {
	memset(v, false, sizeof(v));
	queue<ptr> q;
	q.push({ 0, a, b, 0 });
	v[0][a][b] = true;
	while (!q.empty()) {
		ptr c = q.front();
		q.pop();

		if (c.a == c.b) return c.cnt;

		int left, right;
		if (c.t) { // B 차례라면
			left = (c.b + n - db) % n;
			right = (c.b + db) % n;
			if (!v[!c.t][c.a][left]) {
				q.push({ !c.t, c.a, left, c.cnt + 1 });
				v[!c.t][c.a][left] = true;
			}
			if (!v[!c.t][c.a][right]) {
				q.push({ !c.t, c.a, right, c.cnt + 1 });
				v[!c.t][c.a][right] = true;
			}
		}
		else {
			left = (c.a + n - da) % n;
			right = (c.a + da) % n;
			if (!v[!c.t][left][c.b]) {
				q.push({ !c.t, left, c.b, c.cnt + 1 });
				v[!c.t][left][c.b] = true;
			}
			if (!v[!c.t][right][c.b]) {
				q.push({ !c.t, right, c.b, c.cnt + 1 });
				v[!c.t][right][c.b] = true;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
	a--, b--;
	int ans = solve();
	if(ans < 0) puts("Evil Galazy");
	else printf("%d\n", ans);
	return 0;
}