#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {-1, 0, 1, 0};

typedef long long lld;

int main() {
	int n, days;
	scanf("%d %d", &days, &n);

	ii plan[1005];
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &plan[i].first, &plan[i].second);
	}

	int dp[1005] = {};
	sort(plan, plan + n, [] (const ii& a, const ii& b) {
		return a.second < b.second;
	});
	for (int i = 0; i < n; ++i) {
		int cstart = plan[i].first, cend = plan[i].second;
		dp[i] = cstart - 1; // 1일부터 시작일 앞까지 개수
		for (int j = 0; j < i; ++j) {
			int pstart = plan[j].first, pend = plan[j].second;
			// 이전에 끼워 넣을 수 있는 여행 일정
			if (cstart > pend) {
				// 그 일정의 정답과, 나 사이의 개수 중 큰 것
				dp[i] = min(dp[i], max(dp[j], cstart - pend - 1));
			}
		}
	}

	int ans = days;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, max(dp[i], days - plan[i].second));
	}
	printf("%d\n", ans);

	return 0;
}