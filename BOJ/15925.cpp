#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int n, k, a[31][31];

int count(int x) {
	int sum = 0;
	FOR(i, n) FOR(j, n) sum += x == a[i][j];
	return sum;
}

bool rowchk(int y, int x, int k) {
	int sum = 0;
	FOR(i, n) sum += a[i][x] == k;
	bool changed = false;
	if (sum > n / 2) {
		FOR(i, n) {
			changed |= a[i][x] != k;
			a[i][x] = k;
		}
	}
	return changed;
}

bool colchk(int y, int x, int k) {
	int sum = 0;
	FOR(i, n) sum += a[y][i] == k;
	bool changed = false;
	if (sum > n / 2) {
		FOR(i, n) {
			changed |= a[y][i] != k;
			a[y][i] = k;
		}
	}
	return changed;
}

void print() {
	FOR(i, n) {
		FOR(j, n) {
			printf("%d", a[i][j]);
		}
		puts("");
	}
	puts("");
}

int main() {
	scanf("%d %d", &n, &k);
	FOR(i, n) {
		FOR(j, n) {
			scanf("%d", &a[i][j]);
		}
	}

	int cnt = 0;
	while (cnt = count(k)) {
		bool flag = false;
		FOR(i, n) {
			FOR(j, n) {
				flag |= rowchk(i, j, k) | colchk(i, j, k);
			}
		}

		if (cnt == n * n) return puts("1"), 0;
		if (!flag) break;
	}
	puts("0");

	return 0;
}