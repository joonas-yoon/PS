#include <bits/stdc++.h>
using namespace std;

int a[1 << 11];
vector<int> t[11];

void dfs(int l, int r, int dep = 0) {
	if (l > r) return;
	int mid = (l + r + 1) / 2;
	t[dep].push_back(a[mid]);
	dfs(l, mid - 1, dep + 1);
	dfs(mid + 1, r, dep + 1);
}

int main() {
	int depth;
	scanf("%d", &depth);
	int n = (1 << depth) - 1;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	dfs(0, n - 1);
	for (int i = 0; i < depth; ++i) {
		for (auto& x : t[i]) printf("%d ", x);
		puts("");
	}
	return 0;
}