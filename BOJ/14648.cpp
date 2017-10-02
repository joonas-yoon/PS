#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n;
vector<lld> t;

void build(){
	for (int i = n - 1; i > 0; --i) {
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
}

void update(int k, lld val) {
	for (t[k += n] = val; k > 1; k >>= 1) {
		t[k >> 1] = t[k] + t[k ^ 1];
	}
}

lld query(int l, int r) { // [l, r)
	lld sum = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main() {
	int q;
	scanf("%d %d", &n, &q);
	t.resize(2 * n);
	for (int i = 0; i < n; ++i) scanf("%lld", &t[n + i]);
	build();
	while (q--) {
		int x, a, b, c, d;
		scanf("%d %d %d", &x, &a, &b);
		lld sum = query(a - 1, b);
		if (x == 1) {
			printf("%lld\n", sum);
			lld oa = t[n + a - 1], ob = t[n + b - 1];
			update(a - 1, ob);
			update(b - 1, oa);
		}
		else {
			scanf("%d %d", &c, &d);
			printf("%lld\n", sum - query(c - 1, d));
		}
	}
	return 0;
}