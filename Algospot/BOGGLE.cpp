#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long lld;

#define INF 987654321
#define LINF (LLONG_MAX>>2)

typedef pair<int, int> ii;

char board[5][5];

int dy[] = { -1,0,1,-1,1,-1,0,1 };
int dx[] = { -1,-1,-1,0,0,1,1,1 };

int dp[5][5][11];

int dfs(int y, int x, char *word) {
	if (y < 0 || y >= 5 || x < 0 || x >= 5) return 0;
	if (strlen(word) < 1) return 1;
	if (word[0] != board[y][x]) return 0;

	int& ret = dp[y][x][strlen(word)];
	if (ret != -1) return ret == 1;

	ret = 0;
	for (int d = 0; d < 8; ++d) {
		if (ret = dfs(y + dy[d], x + dx[d], word + 1)) return ret;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		for (int i = 0; i < 5; ++i) scanf("%s ", board[i]);
		int N;
		scanf("%d ", &N);
		while (N--) {
			char word[11];
			scanf("%s ", word);

			memset(dp, -1, sizeof(dp));

			bool find = false;
			for (int r = 0; r < 5; ++r) {
				for (int c = 0; c < 5; ++c) {
					find |= dfs(r, c, word);
					if (find) break;
				}
				if (find) break;
			}
			printf("%s %s\n", word, find ? "YES" : "NO");
		}
	}

	return 0;
}