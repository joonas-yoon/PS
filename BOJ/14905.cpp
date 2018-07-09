#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;

int era[((int)(1e8) / 32) + 1];
void _set(int x) {
	era[x / 32] |= 1 << (x % 32);
}
bool _get(int x) {
	int b = 1 << (x % 32);
	return (era[x / 32] & b) == b;
}

// 더해서 n을 만드는 소수 2개
ii component(vector<int>& p, int n) {
	for (auto& a : p) {
		if (binary_search(all(p), n - a))
			return ii(a, n - a);
	}
	return ii(0, 0);
}

int main() {
	vector<int> primes;
	int MAX_N = 1e3;
	_set(0), _set(1);
	for (int i = 2; i <= MAX_N; ++i) {
		if (_get(i)) continue;
		primes.push_back(i);
		for (lld j = (lld)i * i; j <= MAX_N; j += i)
			_set(j);
	}

	int n, pl = primes.size();
	while (~scanf("%d", &n)) {
		if (n < 8) {
			puts("Impossible.");
			continue;
		}

		for (int i = 4; i <= n - 4; ++i) {
			ii a = component(primes, i);
			ii b = component(primes, n - i);
			if (a.first + a.second + b.first + b.second == n) {
				printf("%d %d %d %d", a.first, a.second, b.first, b.second);
				break;
			}
		}
		puts("");
	}
	return 0;
}