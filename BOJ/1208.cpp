#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

typedef long long lld;

vector<int> getSubSum(vector<int> v) {
	int n = v.size();
	vector<int> ret;
	for (int bit = (1 << n) - 1; bit; --bit) {
		int subsum = 0;
		for (int idx = 0, j = bit; j; j /= 2, idx++) {
			if (j % 2) subsum += v[idx];
		}
		ret.push_back(subsum);
	}
	return ret;
}

int countEqualRange(vector<int>& v, int x) {
	auto p = equal_range(all(v), x);
	int range = p.second - p.first;
	return range;
}

int main() {
	int n, s;
	scanf("%d %d", &n, &s);

	vector<int> a, b;
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (i < n / 2) a.push_back(x);
		else b.push_back(x);
	}

	vector<int> sa = getSubSum(a);
	vector<int> sb = getSubSum(b);
	sort(all(sa));
	sort(all(sb));

	lld ans = 0;
	for (int i = 0; i < sa.size(); ++i) {
		// sa[i] + sb[j] == s 가 되는 쌍을 찾는다
		ans += countEqualRange(sb, s - sa[i]);
	}
	ans += countEqualRange(sa, s); 
	ans += countEqualRange(sb, s);

	printf("%lld\n", ans);

	return 0;
}