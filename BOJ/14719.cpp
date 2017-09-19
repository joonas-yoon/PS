#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	vector<int> a(w, 0);
	int maxH = 0;
	for (int i = 0; i < w; ++i) scanf("%d", &a[i]), maxH = max(maxH, a[i]);
	vector<int> v(w, maxH);
	for (int i = 0, m = a[i]; i < w; ++i) {
		m = max(m, a[i]);
		v[i] = min(v[i], m);
	}
	for (int i = w - 1, m = a[i]; i >= 0; --i){
		m = max(m, a[i]);
		v[i] = min(v[i], m);
	}
	int ans = 0;
	for (int i = 0; i < w; ++i) {
		ans += v[i] - a[i];
	}
	printf("%d\n", ans);
	return 0;
}