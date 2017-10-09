#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, w;
	while (~scanf("%d %d", &n, &w) && n) {
		int x, h[11] = {}, W = 1, H = 0;
		while (n--) {
			scanf("%d ", &x);
			int k = x / w;
			W = max(W, k);
			H = max(H, h[k] += 1);
		}
		double ans = 0.01;
		for (int i = 0; i < W; ++i) {
			ans += (W - i + 1e-12) * h[i] / W / H;
		}
		printf("%.8f\n", ans);
	}
	return 0;
}