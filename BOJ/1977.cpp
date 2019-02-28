#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const int INF = 0x3f3f3f3f;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int m = INF;
	lld sum = 0;
	for (int i = (int)ceil(sqrt(a)); i * i <= b; ++i) {
		sum += (lld)i * i;
		m = min(m, i * i);
	}

	if (sum == 0) return puts("-1"), 0;
	printf("%lld\n%d\n", sum, m);

	return 0;
}