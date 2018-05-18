#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3F3F3F3F;

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { -1, 0, 1, 0 };

#define U (1<<0)
#define R (1<<1)
#define D (1<<2)
#define L (1<<3)

vector<int> moving[5] = {
	{U, R, D, L},
	{U|D, R|L},
	{U|R, U|L, D|R, D|L},
	{U|R|L, D|R|L, R|U|D, L|U|D},
	{U|R|D|L}
};

int h, w, g[9][9];
int direct[10];   // 순서대로 등장한 cctv의 방향
vector<int> cctv; // 순서대로 등장한 cctv의 종류
vector<ii> cctvs; // 순서대로 등장한 cctv의 위치

int solve(int cur) {
	if (cur == (int)cctv.size()) {
		int temp[9][9];
		memcpy(temp, g, sizeof(temp));

		for (int i = 0; i < (int)cctvs.size(); ++i) {
			int y = cctvs[i].first, x = cctvs[i].second;
			int type = cctv[i] - 1;
			for (int j = 0; j < 4; ++j) {
				if (moving[type][direct[i]] & (1 << j)) {
					for (int cy = y, cx = x;; cy += dy[j], cx += dx[j]) {
						if (cy < 0 || cy >= h || cx < 0 || cx >= w || temp[cy][cx] == 6) break;
						temp[cy][cx] = -1;
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				sum += temp[i][j] == 0;
		return sum;
	}

	int ret = INF;
	for (int i = 0; i < (int)moving[cctv[cur] - 1].size(); ++i) {
		direct[cur] = i;
		ret = min(ret, solve(cur + 1));
	}
	return ret;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &g[i][j]);
			if (1 <= g[i][j] && g[i][j] <= 5) {
				cctv.push_back(g[i][j]);
				cctvs.push_back(make_pair(i, j));
			}
		}
	}
	printf("%d\n", solve(0));
	return 0;
}