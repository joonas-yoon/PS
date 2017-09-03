#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	while (~scanf("%d %d %d %d", &a, &b, &c, &d) && a && b && c && d) {
		double area = 0;
		int ans = 0;
		for (int i = 0; i < 2; ++i) {
			double ratio = min(1.*c / b, 1.*d / a);
			if (area < a * b * ratio * ratio) {
				area = a * b * ratio * ratio;
				ans = 100 * min(1.0, ratio);
			}
			swap(a, b);
		}
		printf("%d%%\n", ans);
	}
	return 0;
}