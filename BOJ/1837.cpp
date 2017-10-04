#include <bits/stdc++.h>
using namespace std;

using lld = long long;

bool era[1000001];
vector<int> primes;

int mod(char *p, int k) {
	int sum = 0;
	for (int i = 0; p[i]; ++i) {
		sum = (10 * sum + p[i] - '0') % k;
	}
	return sum;
}

int main() {
	era[0] = era[1] = true;
	for (int i = 2; i <= 1e6; ++i) {
		if (era[i]) continue;
		for (lld j = (lld)i*i; j <= 1e6; j += i) era[j] = true;
		primes.push_back(i);
	}

	int k;
	char p[101];
	scanf("%s %d", p, &k);

	for (auto& pr : primes) {
		if (pr >= k) break;
		if (mod(p, pr) == 0) return printf("BAD %d\n", pr), 0;
	}
	puts("GOOD");
	return 0;
}