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

bool solve(int a[], int n) {
	int c[101], r[101];
	bool used[101] = {};
	for (int i = 0; i < n; ++i) c[i] = i;
	for (int i = n - 1; i >= 0; --i) {
		bool find = false;
		for (int j = n - 1; j >= 0; --j) {
			if (!used[j] && c[j] == a[i]) {
				r[i] = j + 1;
				find = used[j] = true;
				for (int k = j; k < n; ++k) c[k]--;
				break;
			}
		}
		if (!find) return false;
	}
	for (int i = 0; i < n; ++i) printf("%d ", r[i]);
	puts("");
	return true;
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		int n, a[101];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		if (!solve(a, n)) puts("IMPOSSIBLE");
	}
	return 0;
}