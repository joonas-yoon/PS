#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	int n;
	scanf("%d ", &n);
	while (n--) {
		lld x;
		scanf("%lld", &x);
		lld half = sqrt(x);
		printf("%d ", half*half == x);
	}

	return 0;
}