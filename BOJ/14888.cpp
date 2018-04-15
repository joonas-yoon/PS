#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)
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

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

int n, A[12], op[12];
int maxres = -INF, minres = INF;

// 조건: o는 0, 1, 2, 3 중에 반드시 있다.
int calc2(int a, int o, int b) {
	if (o == 0) return a + b;
	if (o == 1) return a - b;
	if (o == 2) return a * b;
	return a / b;
}

void calc(int a, int b, int c, int d, int depth = 0) {
	if (a < 0 || b < 0 || c < 0 || d < 0) return;
	if (!a && !b && !c && !d) {
		int res = A[0];
		for (int i = 0; i < n - 1; ++i)
			res = calc2(res, op[i], A[i + 1]);
		maxres = max(maxres, res);
		minres = min(minres, res);
		return;
	}

	op[depth] = 0;
	calc(a - 1, b, c, d, depth + 1);

	op[depth] = 1;
	calc(a, b - 1, c, d, depth + 1);

	op[depth] = 2;
	calc(a, b, c - 1, d, depth + 1);

	op[depth] = 3;
	calc(a, b, c, d - 1, depth + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	calc(a, b, c, d);
	printf("%d\n%d\n", maxres, minres);
	return 0;
}