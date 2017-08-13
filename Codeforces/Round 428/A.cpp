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
	scanf("%d %d", &n, &k);
	int sum = 0, rest = 0, day = -1;
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);

		x += rest;
		if (x > 8) {
			sum += 8;
			x -= 8;
		}
		else {
			sum += x;
			x -= x;
		}
		rest = x;

		if (sum >= k) {
			day = i + 1;
			break;
		}
	}

	if (day == -1) puts("-1");
	else printf("%d", day);

	return 0;
}