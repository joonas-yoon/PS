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

class matrix {
public:
	lld a, b, c, d;

	matrix() { a = b = c = d = 0; }
	matrix(lld a, lld b, lld c, lld d) :a(a), b(b), c(c), d(d) {}
	matrix(const matrix& m) {
		a = m.a; b = m.b; c = m.c; d = m.d;
	}
	~matrix() {}

	matrix operator % (lld n) const {
		return matrix(a%n, b%n, c%n, d%n);
	}

	matrix operator + (matrix m) const {
		return matrix(a + m.a, b + m.b, c + m.c, d + m.d) % MOD;
	}

	matrix operator * (matrix m) const {
		return matrix(
            m.a*a + m.c*b,
			m.b*a + m.d*b,
			m.a*c + m.c*d,
			m.b*c + m.d*d
        ) % MOD;
	}

	matrix pow(lld n) const {
		matrix m(a, b, c, d);
		if (n < 2) return m;
		m = m.pow(n / 2);
		m = m * m;
		if (n % 2) m = m * matrix(a, b, c, d);
		return m % MOD;
	}
};

int main() {
	matrix m(1, 1, 1, 0);
	lld n;
	scanf("%lld", &n);
	n -= n % 2;
	// n번째까지의 짝수번째 합은 F(n+1)-1
	printf("%lld", m.pow(n).a - 1LL);
	return 0;
}