#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

vector<vector<int>> rotator = {
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

void rotate(vector<int>& clocks, int clock_id) {
	static int times[] = { 12, 3, 6, 9 };
	for (auto& r : rotator[clock_id]) {
		clocks[r] = times[((clocks[r] / 3) % 4 + 1) % 4];
	}
}

int solve(vector<int> clocks, int cur, int t = 0) {
	if (cur >= rotator.size()) {
		bool find = true;
		for (auto& c : clocks) {
			find &= c == 12;
			if (!find) break;
		}
		if (find) return 0;

		return INF;
	}

	int ret = INF;
	for (int times = 0; times < 4; ++times) {
		ret = min(ret, times + solve(clocks, cur + 1, times));
		rotate(clocks, cur);
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<int> a(16);
		for (auto& x : a) scanf("%d", &x);
		int ans = solve(a, 0);
		printf("%d\n", ans < INF ? ans : -1);
	}
	return 0;
}