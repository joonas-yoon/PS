#include <cstdio>

int main() {
	int score[2][9] = {};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &score[i][j]);
		}
	}

	bool ulimWin = false;
	int wscore = 0, gscore = 0;
	for (int i = 0; i < 9; ++i) {
		wscore += score[0][i];
		ulimWin |= wscore > gscore;
		gscore += score[1][i];
	}
	puts(ulimWin ? "Yes" : "No");
    return 0;
}