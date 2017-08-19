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
	int n;
	scanf("%d", &n);
	int odd = 0;
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		odd += x % 2;
	}
	puts(odd > 0 ? "First" : "Second");

	return 0;
}