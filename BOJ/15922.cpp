#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

typedef long long lld;

int main() {
	int n;
	scanf("%d", &n);
	vector<ii> a(n);
	for (auto& x : a) scanf("%d %d", &x.first, &x.second);
	sort(all(a));

	lld ans = 0;
	int ep = a[0].first, sp = ep;
	for (int i = 0; i < n; ++i) {
		int start = a[i].first, end = a[i].second;
		if (ep >= start) {
			ep = max(ep, end);
		} else {
			ans += ep - sp;
			sp = start;
			ep = end;
		}
	}
	ans += ep - sp;

	printf("%lld\n", ans);

	return 0;
}