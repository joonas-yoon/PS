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

int main() {
	int n, k;
	char s[1001];
	scanf("%d %d %s", &n, &k, s);
	int fr[26] = {};
	for (int i = 0; i < n; ++i) fr[s[i] - 'a']++;
	for (int i = 0; i < 26; ++i) if (fr[i] > k) return puts("NO"), 0;
	puts("YES");
	return 0;
}