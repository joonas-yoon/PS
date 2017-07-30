#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m;
		scanf("%d", &m);
		priority_queue<int> minq, maxq;
		printf("%d\n", (m + 1) / 2);
		for (int x, i = 0, cnt = 0; i < m; ++i) {
			scanf("%d", &x);
			minq.push(x);
			while (minq.size() > maxq.size()) {
				maxq.push(-minq.top());
				minq.pop();
			}
			while (minq.size() < maxq.size()) {
				minq.push(-maxq.top());
				maxq.pop();
			}
			if (i % 2 == 0) {
				if (++cnt > 10) { puts(""); cnt = 1; }
				printf("%d ", minq.top());
			}
		}
		puts("");
	}
	return 0;
}