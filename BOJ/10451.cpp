#include <cstdio>
#include <cstring>

bool visit[1001];
int a[1001];

bool dfs(int cur) {
	if (visit[cur]) return false;
	visit[cur] = true;
	dfs(a[cur]);
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[i]--;

		int ans = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; ++i) {
			ans += dfs(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}