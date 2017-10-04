#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

// [y][x] 위치를 [k]번의 방향 전환으로 왔을 때, 최소 전환 횟수
int dp[101][101][111][2];
int rightCost[101][101]; // [i][j] -> [i][j+1] 의 비용
int downCost[101][101]; // [i][j] -> [i+1][j] 의 비용

int h, w, L;

#define UP 0
#define LF 1

int getElement(int y, int x, int k, int dr) {
	if (k < 0) return INF;
	return dp[y][x][k][dr];
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int g;
		scanf("%d %d %d %d", &h, &w, &L, &g);
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w - 1; ++j)
				scanf("%d ", &rightCost[i][j]);
		for (int i = 0; i < h - 1; ++i)
			for (int j = 0; j < w; ++j)
				scanf("%d", &downCost[i][j]);

		int maxTurn = min(h, w) * 2;
		for (int i = 0; i < h; ++i) {
			for (int k = 0; k <= maxTurn; ++k) dp[i][0][k][UP] = dp[i][0][k][LF] = (i == 0 ? 0 : dp[i - 1][0][k][UP] + downCost[i - 1][0]);
		}
		for (int i = 0; i < w; ++i) {
			for (int k = 0; k <= maxTurn; ++k) dp[0][i][k][UP] = dp[0][i][k][LF] = (i == 0 ? 0 : dp[0][i - 1][k][UP] + rightCost[0][i - 1]);
		}
		for (int i = 1; i < h; ++i) {
			for (int j = 1; j < w; ++j) {
				for (int k = 0; k <= maxTurn; ++k) {
					dp[i][j][k][UP] = min(getElement(i - 1, j, k, UP), getElement(i - 1, j, k - 1, LF)) + downCost[i - 1][j];
					dp[i][j][k][LF] = min(getElement(i, j - 1, k, LF), getElement(i, j - 1, k - 1, UP)) + rightCost[i][j - 1];
				}
			}
		}

		int ans = INF;
		for (int i = 0; i <= maxTurn; ++i) {
			if (min(dp[h - 1][w - 1][i][UP], dp[h - 1][w - 1][i][LF]) <= g) {
				ans = min(ans, (h + w - 2) * L + i + 1);
			}
		}
		printf("%d\n", ans < INF ? ans: -1);
	}
	return 0;
}