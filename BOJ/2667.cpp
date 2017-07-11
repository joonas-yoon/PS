#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

vector<int> group;
char grid[30][30];

int n, vis[30][30];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int dfs(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] != '1' || vis[y][x] != -1) return 0;

	vis[y][x] = group.size();
	int ret = 1;
	for (int d = 0; d < 4; ++d) {
		ret += dfs(y + dy[d], x + dx[d]);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s ", grid[i]);
	}

	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int count = dfs(i, j);
			if (count) {
				group.push_back(count);
			}
		}
	}
	sort(group.begin(), group.end());
	printf("%d\n", group.size());
	for (auto& g : group)
		printf("%d\n", g);
	return 0;
}