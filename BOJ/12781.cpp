#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

struct line {
	point a, b;
	double m() {
		return (b.y - a.y + .0) / (b.x - a.x);
	}
	// y = m*(x - a.x) + a.y
	bool intersection(line p) {
		double u = (p.b.y - p.a.y)*(b.x - a.x) - (p.b.x - p.a.x)*(b.y - a.y);
		if (abs(u) < 1e-12) return false;

		double _t = (p.b.x - p.a.x)*(a.y - p.a.y) - (p.b.y - p.a.y)*(a.x - p.a.x);
		double _s = (b.x - a.x)*(a.y - p.a.y) - (b.y - a.y)*(a.x - p.a.x);
		double t = _t / u, s = _s / u;
		if (t < 0.0 || t > 1.0 || s < 0.0 || s > 1.0) return false;
		if (_t == 0 && _s == 0) return false;
		return true;
	}
};

int main() {
	line l[2];
	for (int i = 0; i < 4; ++i) {
		point p;
		scanf("%d %d", &p.x, &p.y);
		if (i % 2) l[i / 2].a = p;
		else l[i / 2].b = p;
	}
	puts(l[0].intersection(l[1]) ? "1" : "0");
	return 0;
}