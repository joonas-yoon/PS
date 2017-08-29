#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, h, t;
	scanf("%d %d %d", &w, &h, &t);
	vector<int> x, y;
	x = { 0, w };
	y = { 0, h };
	while (t--) {
		int k, p;
		scanf("%d %d", &k, &p);
		if (k) x.push_back(p);
		else y.push_back(p);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int mw = 0, mh = 0;
	for (int i = 1; i < x.size(); ++i) mw = max(mw, x[i] - x[i - 1]);
	for (int i = 1; i < y.size(); ++i) mh = max(mh, y[i] - y[i - 1]);
	printf("%d\n", mw * mh);
	return 0;
}