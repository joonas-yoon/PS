#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

int main() {
	int n, m;
	while (~scanf("%d %d", &n, &m) && n) {
		vector<ii> point(10001, make_pair(0, 0));
		for (int i = 0; i < n; ++i) {
			for (int x, j = 0; j < m; ++j) {
				scanf("%d", &x);
				point[x].first += 1;
				point[x].second = x;
			}
		}
		sort(point.begin(), point.end());
		int len = point.size(), first = len - 1;
		while (first >= 0 && point[first].first == point[len - 1].first) first--;
		int end = first;
		while (end >= 0 && point[end].first == point[first].first) end--;

		for (int i = end + 1; i <= first; ++i) printf("%d ", point[i].second);
		puts("");
	}
	return 0;
}