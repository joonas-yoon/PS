#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int R, C;

int canFoot[1000][1001];

bool inRange(int y, int x) { return 0 <= y && y < R && 0 <= x && x < C; }

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			scanf("%d ", &canFoot[i][j]);
		}
	}
	int N;
	scanf("%d", &N);
	vector<ii> rules(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &rules[i].first, &rules[i].second);
	}

	vector<vector<int>> D(R, vector<int>(C, INF));
	queue<ii> q;
	for (int i = 0; i < C; ++i) {
		if (canFoot[0][i]) {
			q.push({ 0, i });
			D[0][i] = 0;
		}
	}

	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for(auto& rule : rules){
				int ny = cy + rule.first, nx = cx + rule.second;
				if (inRange(ny, nx) && canFoot[ny][nx] && D[ny][nx] > dist + 1) {
					D[ny][nx] = dist + 1;
					q.push({ ny, nx });
				}
			}
		}
		++dist;
	}

	int ans = INF;
	for (int i = 0; i < C; ++i) ans = min(ans, D[R - 1][i]);
	printf("%d", ans < INF ? ans : -1);
	return 0;
}