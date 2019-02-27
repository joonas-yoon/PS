#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const int MAX = 1e7 + 5;

int era[MAX / 32 + 1];

void _set(int x) {
	era[x / 32] |= 1 << (x % 32);
}

bool _get(int x) {
	int b = 1 << (x % 32);
	return b == (era[x / 32] & b);
}

int main() {
	lld a, b;
	scanf("%lld %lld", &a, &b);
	
	_set(0);
	_set(1);
	int ans = 0;
	for (int i = 2; i <= MAX; ++i) {
		if (_get(i)) continue;
		for (lld j = (lld)i * i; j <= MAX; j += i) {
			_set(j);
		}

		lld p = i; // prime number
		for (lld x = p; x <= b / p;) {
			x *= p;
			ans += a <= x && x <= b;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}