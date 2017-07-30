#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		lld a, b;
		scanf("%lld %lld", &a, &b);
		lld x = (lld)round(cbrt(a*b));
		if (a * b != x * x * x) puts("No");
		else if ((a*a) % b) puts("No");
		else if ((b*b) % a) puts("No");
		else puts("Yes");
	}
	return 0;
}