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

bool solve(char *a) {
	stack<char> s;
	for (int i = 0; a[i]; ++i) {
		if (a[i] == ')') {
			if (s.empty()) return false;
			s.pop();
		}
		else s.push(a[i]);
	}
	return s.empty();
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		char s[55];
		scanf("%s ", s);
		puts(solve(s) ? "YES" : "NO");
	}
	return 0;
}