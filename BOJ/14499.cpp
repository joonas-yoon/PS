#include <cstdio>
#include <cstring>

int MAP[20][20];
int H, W;
int curPlane, cy, cx;
int dice[6], bak[6];

void copy(){
	if (MAP[cy][cx] == 0) MAP[cy][cx] = dice[0];
	else {
		dice[0] = MAP[cy][cx];
		MAP[cy][cx] = 0;
	}
	memcpy(bak, dice, sizeof(bak));
}

const int changer[4][6] = {
	{3, 1, 0, 4, 2, 5},
	{2, 1, 4, 0, 3, 5},
	{1, 4, 2, 3, 5, 0},
	{5, 0, 2, 3, 1, 4}
};

void move(int dr) {
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, -1, 1 };
	int ny = cy + dy[dr], nx = cx + dx[dr];
	if (ny < 0 || ny >= H || nx < 0 || nx >= W) return;
	copy();
	for (int i = 0; i < 6; ++i) dice[i] = bak[changer[dr][i]];
	cy = ny;
	cx = nx;
	printf("%d\n", dice[4]);
}

int main() {
	int T;
	scanf("%d %d %d %d %d", &H, &W, &cy, &cx, &T);
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			scanf("%d", &MAP[i][j]);
	while (T--) {
		int dir;
		scanf("%d", &dir);
		move(dir - 1);
	}
	return 0;
}