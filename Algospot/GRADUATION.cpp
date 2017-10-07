#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

int bitCount(int n) {
	int r = 0;
	while (n) {
		r += n & 1;
		n /= 2;
	}
	return r;
}

vector<int> needSbj;
vector<int> subjects;

int dp[12][1 << 12 + 1];

int n, m, k, l;
// 현재 x학기까지 살폈을 때, 들은 과목 정보가 bit라면 최소 몇 학기를 더 다니는가
int graduate(int x, int bit) {
	if (bitCount(bit) >= k) return 0;
	if (x >= m) return INF;

	int& ret = dp[x][bit];
	if (ret != -1) return ret;
	
	ret = graduate(x + 1, bit); // 휴학한다.
	// 현재 학기에서 수강할 수 있는 모든 부분 집합
	for (int take = subjects[x]; take; take = (take - 1) & subjects[x]) {
		// 한 학기에 L개 이상 못 고름
		if (bitCount(take) > l) continue;
		int pretest = 0; // 들어야하는 선수과목
		for (int b = take, s = 0; b; s++, b /= 2) {
			if (b & 1) pretest |= needSbj[s];
		}
		// 선수과목과 듣지 않은 과목이 공집합이 아니면
		if (pretest & ~(bit)) continue;
		ret = min(ret, 1 + graduate(x + 1, bit | take));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &n, &k, &m, &l);
		needSbj.assign(n, 0);
		for (int rn, ri, i = 0; i < n; ++i) {
			scanf("%d", &rn);
			while (rn--) {
				scanf("%d", &ri);
				needSbj[i] |= 1 << ri;
			}
		}

		subjects.assign(m, 0);
		for (int cn, ci, i = 0; i < m; ++i) {
			scanf("%d", &cn);
			while (cn--) {
				scanf("%d", &ci);
				subjects[i] |= (1 << ci);
			}
		}

		memset(dp, -1, sizeof(dp));
		int ans = graduate(0, 0);
		if (ans < INF) printf("%d\n", ans);
		else puts("IMPOSSIBLE");
	}
	return 0;
}