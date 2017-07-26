#include <bits/stdc++.h>
using namespace std;

int n, a[101];
bool vis[101];

bool f(const int& start, int next) {
	if (start == next) return true;
	bool& ret = vis[next];
	if (ret) return 0;
	ret = true;
	return ret = f(start, a[next]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		memset(vis, false, sizeof(vis));
		bool search = f(i, a[i]);
		if (search) ans.push_back(i);
	}

	printf("%d\n", ans.size());
	for (auto& x : ans) {
		printf("%d\n", x);
	}

	return 0;
}