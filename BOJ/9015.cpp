#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

struct point {
	int y, x;
	bool operator == (const point& p) const {
		return p.y == y && x == p.x;
	}
	bool operator < (const point& p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
};

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<point> pt(n);
		for (int y, x, i = 0; i < n; ++i) {
			scanf("%d %d", &y, &x);
			pt[i] = { y, x };
		}
		sort(pt.begin(), pt.end());
		int area = 0, size = pt.size();
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				int a = pt[i].y, b = pt[i].x;
				int c = pt[j].y, d = pt[j].x;
				int x = c - a, y = d - b;
				point p1 = { a + y, b - x };
				point p2 = { c + y, d - x };
                int thisSize = x*x + y*y;
				if (thisSize <= area || !binary_search(pt.begin(), pt.end(), p1)) continue;
				if (binary_search(pt.begin(), pt.end(), p2)) area = max(area, thisSize);
			}
		}
		printf("%d\n", area);
	}
	return 0;
}