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
	vector<ii> a(n + 1);
	FOR(i, n) scanf("%d %d", &a[i].first, &a[i].second);
	int ans = 0;
	FOR(i, n) {
		int x = abs(a[i].first - a[(i - 1 + n) % n].first);
		int y = abs(a[i].second - a[(i - 1 + n) % n].second);
		ans += x + y;
	}
	printf("%d\n", ans);
	return 0;
}