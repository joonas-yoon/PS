#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld countByMoney(vector<int>& a, lld k) {
	lld cnt = 0;
	lld s = 0;
	for (int i = 0; i < a.size(); ++i) {
		int x = a[i];
		if (s + x > k) {
			cnt += (s + k - 1) / k;
			s = 0;
		}
		s += x;
	}
	cnt += (s + k - 1) / k;
	return cnt;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	lld l = *max_element(a.begin(), a.end()), r = 1e15;
	while (l <= r) {
		lld mid = (l + r) / 2;
		lld cnt = countByMoney(a, mid);
		if (cnt <= m) r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", l);

	return 0;
}