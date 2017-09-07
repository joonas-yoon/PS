#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, w, l;
	scanf("%d %d %d", &n, &w, &l);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int sum = 0, cur = 0, ans = 0;
	queue<int> q;
	while (q.size() < w && cur < n) {
		if (sum + a[cur] <= l) {
			sum += a[cur];
			q.push(a[cur++]);
		}
		else q.push(0);
		++ans;
	}

	while (!q.empty() && cur < n) {
		sum -= q.front();
		q.pop();
		++ans;
		if (cur < n) {
			if (sum + a[cur] <= l) {
				sum += a[cur];
				q.push(a[cur++]);
			}
			else
				q.push(0);
		}
	}
	printf("%d\n", ans + w);

	return 0;
}