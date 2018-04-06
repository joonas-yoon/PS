#include <iostream>
#include <cstdio>
using namespace std;

const long long MOD = 1e6;

typedef long long lld;

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

int main(){
    matrix m(1,1,1,0);
    
    lld n;
    scanf("%lld", &n);
    printf("%lld", m.pow(n-1).a);
    
    return 0;
}