#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	int n, a[100][100];
	scanf("%d", &n);
	FOR(i, n) {
		FOR(j, n)
			scanf("%d", &a[i][j]);
	}
	int gold = n * (n * n + 1) / 2;
	FOR(i, n) {
		int sum = 0;
		FOR(j, n) sum += a[i][j];
		if (sum != gold) return puts("FALSE"), 0;

		sum = 0;
		FOR(j, n) sum += a[j][i];
		if (sum != gold) return puts("FALSE"), 0;
	}

	bool f[10001] = {};
	FOR(i, n) {
		FOR(j, n) {
			if(f[a[i][j]]) return puts("FALSE"), 0;
			f[a[i][j]] = true;
		}
	}

	int sum = 0;
	FOR(i, n) sum += a[i][i];
	if (sum != gold) return puts("FALSE"), 0;

	sum = 0;
	FOR(i, n) sum += a[n - 1 - i][n - 1 - i];
	if (sum != gold) return puts("FALSE"), 0;

	puts("TRUE");
	return 0;
}