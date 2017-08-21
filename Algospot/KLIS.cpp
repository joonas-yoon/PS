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

vector<int> a;
vector<ll> lis; // {cur까지의 최대 길이, 그러한 것의 개수}
ll getLIS(int cur) {
	ll& ret = lis[cur + 1];
	if (ret != make_pair(0LL, 0LL)) return ret;
	ret = { 1, 1 };
	lld m = 1, cnt = 1;
	for (int i = cur + 1; i < a.size(); ++i) {
		if (cur == -1 || a[cur] < a[i]) {
			auto next = getLIS(i);
			if (m < 1 + next.first) {
				m = 1 + next.first;
				cnt = next.second;
			}
			else if (m == 1 + next.first) {
				cnt = min(LINF, cnt + next.second);
			}
		}
	}
	return ret = make_pair(m, cnt);
}

int solve(int cur, lld k, const int& n, vector<int>& ans) {
	if (k < 0) return 0;

	for (int i = cur + 1; i < n; ++i) {
		auto next = getLIS(i);
		if ((cur == -1 || a[cur] < a[i]) && getLIS(cur).first == 1 + next.first) {
			lld m = next.second;
			if (k > m) k -= m;
			else {
				ans.push_back(i);
				return 1 + solve(i, k, n, ans);
			}
		}
	}
  return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		lld n, k;
		scanf("%lld %lld", &n, &k);
		a = vector<int>(n);
		lis = vector<ll>(n+1, make_pair(0, 0));

		vector<ii> p(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i].first);
			p[i].second = i;
		}
		sort(p.begin(), p.end());
		for (int i = 0; i < n; ++i) {
			a[i] = p[i].second;
		}

		vector<int> ans;
		printf("%d\n", solve(-1, k, n, ans));
		for (auto& x : ans) printf("%d ", p[x].first);
		puts("");
	}
	return 0;
}