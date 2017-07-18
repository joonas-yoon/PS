#include <cstdio>
#include <cstring>

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

int h, w;
char s[16][16];
int py, px;

bool isGoal[16][16];

int directToInt(char dirt) {
	if (dirt == 'U') return 0;
	if (dirt == 'D') return 1;
	if (dirt == 'L') return 2;
	return 3;
}

bool canGo(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w && s[y][x] != '#'; }

void move(char dirt) {
	int d = directToInt(dirt);
	int ny = py + dy[d], nx = px + dx[d];
	if (!canGo(ny, nx)) return;

	// 그냥 캐릭만 이동
	if (s[ny][nx] == '.') {
		s[py][px] = '.';
		py = ny, px = nx;
		s[ny][nx] = isGoal[ny][nx] ? 'W' : 'w';
		return;
	}

	int nny = ny + dy[d], nnx = nx + dx[d];
	// 막혀서 못 움직임
	if (!canGo(nny, nnx) || s[nny][nnx] != '.') return;
	
	s[nny][nnx] = s[ny][nx];
	if (s[nny][nnx] == 'b' && isGoal[nny][nnx]) s[nny][nnx] = 'B';
	if (s[nny][nnx] == 'B' && !isGoal[nny][nnx]) s[nny][nnx] = 'b';

	s[ny][nx] = isGoal[ny][nx] ? 'W' : 'w';
	s[py][px] = '.';
	py = ny, px = nx;
}

bool gameEnd() {
	bool complete = true;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (isGoal[i][j]) {
				complete &= s[i][j] == 'B';
			}
		}
	}
	return complete;
}

void print() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c = s[i][j];
			if (isGoal[i][j] && c == '.') putchar('+');
			else putchar(s[i][j]);
		}
		puts("");
	}
}

int main() {
	int round = 1;
	while (~scanf("%d %d", &h, &w) & h) {
		memset(isGoal, false, sizeof(isGoal));
		memset(s, 0, sizeof(s));

		for (int i = 0; i < h; ++i) {
			scanf("%s ", s[i]);
			for (int j = 0; j < w; ++j) {
				char c = s[i][j];
				isGoal[i][j] = c == 'W' || c == 'B' || c == '+';

				if (c == 'W' || c == 'w') py = i, px = j;
				if (c == '+') s[i][j] = '.';
			}
		}

		char cmd[51];
		scanf("%s ", cmd);
		bool complete = false;
		for (int i = 0; cmd[i]; ++i) {
			move(cmd[i]);
			complete |= gameEnd();
			if (complete) break;
		}
		printf("Game %d: %s\n", round++, complete ? "complete" : "incomplete");
		print();
	}

	return 0;
}