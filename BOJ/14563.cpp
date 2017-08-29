#include <cstdio>

typedef long long lld;

lld divsum(int n) {
	lld sum = 0;
	for (lld i = 1; i*i <= n; ++i) {
		if (n % i == 0) {
			if (n != 1) sum += i;
			if (i * i != n && i != 1) sum += n / i;
		}
	}
	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		lld x;
		scanf("%lld", &x);
		lld s = divsum(x);
		puts(s <= x ? (s == x ? "Perfect" : "Deficient") : "Abundant");
	}
	return 0;
}