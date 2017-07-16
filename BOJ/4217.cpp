#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

int h, w;
char board[255][255];
char _board[255][255];

int groupId[255][255];

bool inRange(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; }

void init() {
	memset(board, 0, sizeof(board));
	memset(_board, 0, sizeof(board));
	memset(groupId, -1, sizeof(groupId));
}

int removeZero(queue<ii>& q, int y, int x) {
	if (board[y][x] == '1') return 0;

	if (y != -1) {
		q.push({ y, x });
		board[y][x] = 0;
	}

	int r = 0;
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		++r;

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (inRange(ny, nx) && board[ny][nx] == '0') {
				board[ny][nx] = 0;
				q.push({ ny, nx });
			}
		}
	}
	return r;
}

int giveId(queue<ii>& q, int y, int x, const int id) {
	if (board[y][x] != '1' || groupId[y][x] != -1) return 0;

	q.push({ y, x });
	groupId[y][x] = id;
	int r = 1;
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		++r;
		
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (inRange(ny, nx) && board[ny][nx] == '1' && groupId[ny][nx] == -1) {
				groupId[ny][nx] = id;
				q.push({ ny, nx });
			}
		}
	}
	return r;
}

queue<ii> q;
vector<int> groups;

int main() {
	int Tcase = 1;
	while (~scanf("%d%d ", &h, &w) && h && w) {
		init();

		for (int i = 0; i < h; ++i) {
			scanf("%s ", _board[i]);
			for (int j = 0; j < w; ++j) {
				char ch = _board[i][j];
				int dig = ch >= '0' && ch <= '9' ? ch - '0' : ch - 'a' + 10;
				for (int k = 0; k < 4; ++k) {
					board[i][4 * j + k] = '0' + ((dig & (1 << (3 - k))) != 0);
				}
			}
		}

		w *= 4;

		for (int i = 0; i < h; ++i) {
			if (board[i][0] == '0') q.push({ i, 0 }), board[i][0] = 0;
			if (board[i][w - 1] == '0') q.push({ i, w - 1 }), board[i][w - 1] = 0;
		}
		for (int i = 0; i < w; ++i) {
			if (board[0][i] == '0') q.push({ 0, i }), board[0][i] = 0;
			if (board[h - 1][i] == '0') q.push({ h - 1, i }), board[h - 1][i] = 0;
		}
		removeZero(q, -1, -1);

		groups = vector<int>();

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (giveId(q, i, j, groups.size())) {
					groups.push_back(0);
				}
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (board[i][j] == '0') {
					int cnt = removeZero(q, i, j);
					int gid = -1;
					for (int d = 0; d < 8; ++d) {
						int ny = i + dy[d], nx = j + dx[d];
						if (!inRange(ny, nx)) continue;
						if ((gid = groupId[ny][nx]) != -1) break;
					}
                    if( gid != -1 ) groups[gid] += 1;
				}
			}
		}

		string answer;
		for(auto& fr : groups){
			answer.push_back("WAKJSD"[fr]);
		}
		sort(answer.begin(), answer.end());

		printf("Case %d: ", Tcase++);
		puts(answer.c_str());
	}
	return 0;
}