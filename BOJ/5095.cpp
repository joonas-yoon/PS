#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

class matrix {
public:
	const static int MAX_SIZE = 101;
	lld A[MAX_SIZE][MAX_SIZE];
	int row, col, _mod;
public:
	matrix(int r = 2, int c = 2, bool E = false) : _mod(MOD) {
		row = r; col = c;
		memset(A, 0LL, sizeof(A));
		if (E) {
			// 단위행렬
			for (int i = 0; i<MAX_SIZE; ++i) A[i][i] = 1;
		}
	}
	matrix(const matrix& m) {
		row = m.row; col = m.col;
		for (int i = 0; i<row; ++i) {
			for (int j = 0; j<col; ++j) {
				A[i][j] = m.A[i][j];
			}
		}
	}
	~matrix() {}

	void setMod(int m) { _mod = m; }

	matrix operator + (const matrix& m) {
		for (int i = 0; i<row; ++i) {
			for (int j = 0; j<col; ++j) {
				A[i][j] += m.A[i][j];
			}
		}
		return *this;
	}

	matrix operator * (const matrix& m) {
		matrix r(row, m.col);
		for (int i = 0; i<row; ++i) {
			for (int k = 0; k<m.col; ++k) {
				lld s = 0;
				for (int j = 0; j<col; ++j)
					s += this->A[i][j] * m.A[j][k];
				r.A[i][k] = s;
			}
		}
		return r;
	}

	matrix& operator % (int mod) {
		for (int i = 0; i<row; ++i) {
			for (int j = 0; j<col; ++j) {
				A[i][j] %= mod;
			}
		}
		return *this;
	}

	matrix pow(matrix r, lld b) {
		if (b < 2) return r % _mod;
		matrix r2 = pow(r, b / 2) % _mod, rr = (r2 * r2) % _mod;
		if (b & 1) return (rr * r) % _mod;
		return rr;
	}

	void print() {
		for (int i = 0; i<row; ++i) {
			for (int j = 0; j<col; ++j) {
				printf("%lld ", A[i][j]);
			}
			puts("");
		}
	}
};

int main() {
	int n, mod, k;
	while (~scanf("%d %d %d", &n, &mod, &k) && n) {
		matrix a(n, n);
		a.setMod(mod);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a.A[i][j]);

		puts("");
		a.pow(a, k).print();
	}
	return 0;
}