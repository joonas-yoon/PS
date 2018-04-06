#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

// (rad)^2
double dist(double x1, double x2, double y1, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<double> X(n), Y(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf ", &X[i], &Y[i]);
	}

	double delta = 1.0;
	double x = X[0], y = Y[0];
	int tries = 10000, t = 1;
	while (tries--) {
		double nx = X[0], ny = Y[0], nd = 0;
		for (int i = 0; i < n; ++i) {
			double nrad = dist(x, X[i], y, Y[i]);
			if (nd < nrad) {
				nx = X[i], ny = Y[i], nd = nrad;
			}
		}

		x += (nx - x + EPS) * delta;
		y += (ny - y + EPS) * delta;
		delta *= 0.95;
	}

	double rad = 0;
	for (int i = 0; i < n; ++i) {
		rad = std::max(rad, dist(x, X[i], y, Y[i]));
	}
	printf("%.4lf %.4lf %.8lf\n", x, y, sqrt(rad));
	return 0;
}