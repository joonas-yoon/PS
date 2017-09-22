#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::ios::sync_with_stdio(false)

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int main() {
	int T;
	scanf("%d ", &T);
	lld fibo[71] = { 0,1 };
	for (int i = 2; i < 70; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	while (T--) {
		lld n;
		scanf("%lld", &n);
		lld answer[70];
		int len = 0;
		while (n > 0) {
			auto it = upper_bound(fibo, fibo + 70, n);
			--it;
			answer[len++] = *it;
			n -= *it;
		}
		for (int i = len - 1; i >= 0; --i) printf("%lld ", answer[i]);
		puts("");
	}
	return 0;
}