#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false);

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

string s;

int dp[10001];

int solve(int cur) {
	int len = s.length();
	if (cur >= len) return 0;

	int& ret = dp[cur];
	if (ret != -1) return ret;
	ret = INF;

	bool allSame = true;
	for (int i = cur + 1; i < len && i < cur + 5; ++i) {
		allSame &= s[i] == s[i - 1];
		if (!allSame) break;
		if (i >= cur + 2) ret = min(ret, 1 + solve(i + 1));
	}

	bool increase = true, decrease = true;
	for (int i = cur + 1; i < len && i < cur + 5; ++i) {
		increase &= s[i - 1] - s[i] == 1;
		decrease &= s[i] - s[i - 1] == 1;
		if (increase && i >= cur + 2) ret = min(ret, 2 + solve(i + 1));
		if (decrease && i >= cur + 2) ret = min(ret, 2 + solve(i + 1));
	}

	bool zigzag = true;
	for (int i = cur + 2; i < len && i < cur + 5; ++i) {
		zigzag &= s[i - 1] != s[i] && s[i - 2] == s[i];
		if (!zigzag) break;
		if (i >= cur + 2) ret = min(ret, 4 + solve(i + 1));
	}

	if (cur + 1 < len) {
		int d = s[cur + 1] - s[cur];
		for (int i = cur + 2; i < len && i < cur + 5; ++i) {
			if (s[i] - s[i - 1] != d) break;
			ret = min(ret, 5 + solve(i + 1));
		}
	}

	for (int i = cur + 2; i < len && i < cur + 5; ++i) {
		ret = min(ret, 10 + solve(i + 1));
	}
	return ret;
}

int main() {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> s;
		cout << solve(0) << '\n';
	}
	return 0;
}