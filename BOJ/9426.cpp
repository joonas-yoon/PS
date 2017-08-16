#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1,1,0,0 };
static int dx[] = { 0,0,-1,1 };

void balance(multiset<int>& sm, multiset<int>& lg) {
	while (sm.size() > lg.size()) {
		int top = *sm.begin();
		sm.erase(sm.find(top));
		lg.insert(-top);
	}
	while (sm.size() < lg.size()) {
		int top = *lg.begin();
		lg.erase(lg.find(top));
		sm.insert(-top);
	}
}

int main() {
	multiset<int> sm, lg;
	int n, k;
	lld sum = 0;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (auto& x : a) scanf("%d", &x);
	for(int i=0; i<n; ++i){
		int x = a[i];
		if (i == 0) sm.insert(-x);
		else {
			if ( !lg.empty() && x < *lg.begin()) sm.insert(-x);
			else {
				if (x > -*sm.begin()) lg.insert(x);
				else sm.insert(-x);
			}

			balance(sm, lg);

			// 넘치면 이전것을 지워야한다.
			if ( i >= k ){
				int old = a[i - k];
				if (!sm.empty() && sm.find(-old) != sm.end()) sm.erase(-old);
				else lg.erase(old);
				balance(sm, lg);
			}
		}

		if (i >= k - 1) {
			sum += -*sm.begin();
		}
	}
	printf("%lld", sum);

	return 0;
}