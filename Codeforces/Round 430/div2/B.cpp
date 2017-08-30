#include <bits/stdc++.h>
using namespace std;

struct ssg {
	int x, y, rad;
};

bool isIn(ssg s, int r, int d) {
	double dist = sqrt(s.x * s.x + s.y * s.y);
	if (r - d - (dist - s.rad) > 1e-12) return false;
	if (dist + s.rad - r > 1e-12) return false;
	return true;
}

int main() {
	int r, d, n;
	scanf("%d %d %d", &r, &d, &n);
	vector<ssg> v;
	for (int x, y, ri, i = 0; i < n; ++i) {
		scanf("%d %d %d", &x, &y, &ri);
		if (2 * ri <= d) {
			v.push_back({ x, y, ri });
		}
	}
	int ans = 0;
	for (auto& cir : v) {
		ans += isIn(cir, r, d);
	}
	printf("%d", ans);
	return 0;
}