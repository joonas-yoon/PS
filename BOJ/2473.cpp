#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	lld a[5001];
	for (int i = 0; i < n; ++i) scanf("%lld ", &a[i]);
	sort(a, a + n);
	lld diff = LINF;
	lld ans[3] = { a[0], a[1], a[2] };
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			int k = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;
			if (k < n) {
				if (diff > abs(a[i] + a[j] + a[k])) {
					diff = abs(a[i] + a[j] + a[k]);
					ans[0] = a[i];
					ans[1] = a[j];
					ans[2] = a[k];
				}
			}
			if (k - 1 > j) {
				--k;
				if (diff > abs(a[i] + a[j] + a[k])) {
					diff = abs(a[i] + a[j] + a[k]);
					ans[0] = a[i];
					ans[1] = a[j];
					ans[2] = a[k];
				}
			}
		}
	}
	sort(ans, ans + 3);
	for (auto& x : ans) printf("%lld ", x);
	return 0;
}
