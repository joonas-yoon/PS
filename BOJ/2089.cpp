#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;

#define MAX_BIT 34

int main() {
	lld n, start[MAX_BIT] = {}, end[MAX_BIT] = {};
	lld ssum = 0, esum = 0;
	for (int i = 2; i < MAX_BIT; i += 2) {
		ssum -= 1LL << (i - 1);
		esum += 1LL << (i - 2);
		start[i] = start[i + 1] = ssum;
		end[i - 1] = end[i] = esum;
	}

	scanf("%lld", &n);
	bool bit[MAX_BIT] = {};
	for (int i = MAX_BIT - 1; i >= 0; --i) {
		lld d = max(n - start[i], end[i] - n);
		lld m = 1LL << i, mm = m << 1;
		bit[MAX_BIT - 1 - i] = d % mm >= m;
	}

	bool leading = false;
	for (int i = 0; i < MAX_BIT; ++i) {
		leading |= bit[i];
		if (leading) printf("%1d", bit[i]);
	}

	if (!leading) puts("0");

	return 0;
}