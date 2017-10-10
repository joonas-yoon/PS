#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	bool v[1001] = {};
	int cur = 0;
	for (int i = 1; i < n; ++i) {
		printf("%d ", cur + 1);
		v[cur] = true;
		int cnt = 0, next = cur, len = abs(a[cur]);
		while (cnt < len) {
			cnt += !v[next];
			if (cnt == len) break;
			if (a[cur] < 0) next = (next + n - 1) % n;
			else next = (next + 1) % n;
		}
		cur = next;
	}
	printf("%d\n", cur + 1);

	return 0;
}