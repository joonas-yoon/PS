#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;

#define INF 987654321
#define LINF (LLONG_MAX>>2)

typedef pair<int, int> ii;

struct query {
	int time, duration, cost;
	bool isOpen;
	bool operator < (const query& q) const {
		if (time == q.time) return isOpen > q.isOpen;
		return time < q.time;
	}
};

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	vector<query> queries;
	for (int i = 0; i < n; ++i) {
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		queries.push_back(query{ l, r - l + 1, c, true });
		queries.push_back(query{ r, r - l + 1, c, false });
	}
	sort(queries.begin(), queries.end());

	vector<lld> bestCost(x + 1, LINF);
	lld ans = LINF;
	for (auto& q : queries) {
		if (!q.isOpen) {
			if (q.duration >= x) continue;
			bestCost[q.duration] = min(bestCost[q.duration], (lld)q.cost);
		} else if (q.duration < x) {
			ans = min(ans, bestCost[x - q.duration] + q.cost);
		}
	}
	printf("%lld", ans < LINF ? ans : -1);

	return 0;
}