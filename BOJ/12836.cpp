#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n;
vector<lld> t;

void build(vector<lld>& a) {
	n = a.size();
	t.resize(2 * n);
	for (int i = 0; i < n; ++i) t[n + i] = a[i];
	for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
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
	int n, q;
	scanf("%d %d", &n, &q);
	vector<lld> a(n, 0);
	build(a);

	while (q--) {
		int c, p, x;
		scanf("%d %d %d", &c, &p, &x);
		if (c == 1) {
			update(p - 1, t[n + p - 1] + x);
		}
		else {
			printf("%lld\n", query(0, x) - query(0, p - 1));
		}
	}

	return 0;
}
