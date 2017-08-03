#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e7;

pair<int, string> dp[101][1001];
ii item[101];

// 담을 수 있는 부피가 w 남았을 때, cur를 담는다/담지 않는다
pair<int, string> pack(int cur, int w) {
	if (w < 0) return { -INF, "" };
	if (cur < 0) return { 0, "" };

	auto& ret = dp[cur][w];
	if (ret.first != -1) return ret;

	auto unpack = pack(cur - 1, w);
	auto withpack = pack(cur - 1, w - item[cur].first);
	withpack.first += item[cur].second;
	ret = max(unpack, withpack);
	ret.second = ret.second + string(1, '0' + (withpack > unpack));
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		fill(&dp[0][0], &dp[100][1000], make_pair(-1, ""));
		int n, w;
		char s[101][21];
		scanf("%d %d", &n, &w);
		for (int i = 0; i < n; ++i) {
			scanf("%s %d %d ", s[i], &item[i].first, &item[i].second);
		}
		auto ans = pack(n - 1, w);
		vector<string> lst;
		for(int i=0; i<n; ++i){
			if (ans.second[i] == '1') lst.push_back(s[i]);
		}
		printf("%d %d\n", ans.first, lst.size());
		for (auto& x : lst) puts(x.c_str());
	}
	return 0;
}