#include <cstdio>

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,1,-1};

int n, poten[4];

bool visit[30][30];

double robot(int step, int y, int x) {
	if (visit[y][x]) return 0;
	if (step >= n) return 1;

	double potential = 0;
	visit[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		potential += (poten[i] / 100.0) * robot(step + 1, ny, nx);
	}
	visit[y][x] = false;
	return potential;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &poten[i]);

	printf("%.9lf\n", robot(0, 15, 15));

	return 0;
}