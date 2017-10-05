#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int dice[6] = {
	1, 2, 3, 5, 4, 6
};

void moveRight() {
	int t[6]; memcpy(t, dice, sizeof(t));
	dice[0] = t[4];
	dice[2] = t[0];
	dice[4] = t[5];
	dice[5] = t[2];
}

void moveLeft() {
	for (int i = 0; i < 3; ++i) moveRight();
}

void moveDown() {
	int t[6]; memcpy(t, dice, sizeof(t));
	dice[0] = t[3];
	dice[1] = t[0];
	dice[3] = t[5];
	dice[5] = t[1];
}

int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	lld ans = 0;
	for (int cr = 1; cr <= r; ++cr) {
		ans += dice[0];
		if (c > 1) {
			int w = (c - 1) % 4;
			int loopSum = dice[0] + dice[2] + dice[4] + dice[5];
			int loop = (c - 1) / 4;
			ans += loop * loopSum;
			for (int k = 0; k < c - 1 - loop * 4; ++k) {
				if (cr % 2 == 0) moveLeft();
				else moveRight();
				ans += dice[0];
			}
		}
		moveDown();
	}
	printf("%lld\n", ans);
	return 0;
}