#include <string>
#include <vector>
#include <utility> // std::pair
#include <algorithm> // std::swap
using namespace std;

using ii = pair<int, int>;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

void force_gravity(int h, int w, vector<string>& board) {
	for (int col = 0; col < w; ++col) {
		string r;
		for (int row = h - 1; row >= 0; --row) {
			if (board[row][col] != '_') r = string(1, board[row][col]) + r;
		}
		while (r.size() < h) r = "_" + r;
		for (int row = 0; row < h; ++row) board[row][col] = r[row];
	}
}

bool blockFour(int h, int w, int y, int x, vector<string> board) {
	if (y + 1 >= h || x + 1 >= w) return false;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (board[y + i][x + j] != board[y][x]) return false;
		}
	}
	return true;
}

int solution(int h, int w, vector<string> board) {
	int answer = 0;
	bool exist;
	do {
		vector<vector<bool>> chk(h, vector<bool>(w, false));
		exist = false;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (board[i][j] != '_' && blockFour(h, w, i, j, board)) {
					for (int r = 0; r < 2; ++r) {
						for (int w = 0; w < 2; ++w) {
							chk[i + r][j + w] = true;
						}
					}
					exist = true;
				}
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (chk[i][j]) {
					board[i][j] = '_';
					answer += chk[i][j];
				}
			}
		}
		force_gravity(h, w, board);
	} while (exist);
	return answer;
}