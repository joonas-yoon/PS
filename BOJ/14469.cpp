#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

int main() {
	int n;
	scanf("%d", &n);
	vector<ii> v(n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end());
	int cur = 0;
	for (auto& x : v) {
		cur = max(x.first, cur);
		cur += x.second;
	}
	printf("%d\n", cur);
	return 0;
}