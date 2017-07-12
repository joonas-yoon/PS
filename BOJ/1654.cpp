#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef long long lld;

#define INF 987654321
#define LINF (LLONG_MAX>>2)

int countCutLan(vector<int>& lans, int cutBy) {
	int count = 0;
	for (auto& lan : lans) {
        count += lan / cutBy;
	}
	return count;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> lan(n);
	for (int i = 0; i < n; ++i) scanf("%d ", &lan[i]);

	lld lo = 1, hi = INT_MAX;
	while (lo <= hi) {
		lld mid = (lo + hi) / 2;
		int count = countCutLan(lan, mid);
		if (count >= k)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	printf("%lld", hi);

	return 0;
}