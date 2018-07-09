#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

const int INF = 0x3F3F3F3F;

int main() {
	fastio();

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n;
		vector<int> a(n);
		FOR(i, n) cin >> a[i];
		sort(all(a));

		cin >> m;
		int ans = INF;
		for (int x, i = 0; i < m; ++i) {
			cin >> x;
			auto l = lower_bound(all(a), x);
			if (l != a.end())
				ans = min(ans, abs(*l - x));
            if (l != a.begin()) {
                l--;
                ans = min(ans, abs(*l - x));
            }
		}
		cout << ans << '\n';
	}

	return 0;
}