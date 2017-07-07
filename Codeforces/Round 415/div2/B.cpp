#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>
#include <tuple>
using namespace std;

typedef long long lld;

#define INF 987654321

typedef pair<int, int> ii;

int main() {
	int n, f;
	scanf("%d %d", &n, &f);
	vector<pair<lld, lld>> prod(n);
	vector<bool> sellout(n, false);
	priority_queue<pair<lld, int>> pq;
	for (int i = 0; i < n; ++i) {
		lld k_i, l_i;
		scanf("%lld %lld", &k_i, &l_i); // k_i개가 있는 데 l_i개를 사감
		prod[i] = { k_i, l_i };
		// 재고를 2배로 올릴 경우 얻을 수 있는 이익
		pq.push({ min(2 * k_i, l_i) - min(k_i, l_i), i });
	}

	while (f-->0 && !pq.empty()) {
		sellout[pq.top().second] = true;
		pq.pop();
	}

	lld ans = 0LL;
	for (int i = 0; i < n; ++i) {
		lld p = prod[i].first;
		if (sellout[i]) p *= 2;
		ans += min(p, prod[i].second);
	}
	printf("%lld", ans);

	return 0;
}