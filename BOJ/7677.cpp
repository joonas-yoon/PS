#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

class matrix {
public:
	const static int MAX_SIZE = 5;
	const static int MOD = 10000;
	lld A[MAX_SIZE][MAX_SIZE];
	int row, col;
public:
	matrix(int r = 2, int c = 2, bool E = false) {
		row = r; col = c;
		memset(A, 0LL, sizeof(A));
		if (E) {
			// 단위행렬
			for (int i = 0; i<MAX_SIZE; ++i) A[i][i] = 1;
		}
	}
	matrix(vector<int> a, int row, int col) {
		this->row = row;
		this->col = col;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				A[i][j] = a[i * row + j];
			}
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
				for (int j = 0; j<col /* == m.row */; ++j)
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
		if (b < 2) return r % MOD;
		matrix r2 = pow(r, b / 2) % MOD, rr = (r2 * r2) % MOD;
		if (b & 1) return (rr * r) % MOD;
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

	lld get(int row, int col) {
		return A[row][col];
	}
};

// a ^ p
matrix fastPow(matrix a, int p) {
	if (p == 0) return matrix(vector<int>{ 1, 1, 1, 0 }, 2, 2);
	if (p == 1) return a;
	matrix half = fastPow(a, p / 2) % 10000, r = (half * half) % 10000;
	if (p & 1) return r * a;
	return r;
}

int main() {
	int n;
	while (~scanf("%d", &n) && n >= 0) {
		matrix a(vector<int>{ 1, 1, 1, 0 }, 2, 2);
		a = fastPow(a, n + 1);
		printf("%lld\n", a.get(1, 1));
	}
	return 0;
}