#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int sticks[10] = {
	6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

// 남은 성냥개비 n개 (naive)
int solve(int n, int p, int sum = 0) {
	if (n < 0) return INF;
	if (n == 0) return sum;

	int ret = INF;
	for (int i = p; i < 10; ++i) {
		ret = min(ret, solve(n - sticks[i], 0, 10 * sum + i));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		if (n < 15) printf("%d", solve(n, 1));
		else {
			char pat[2][8] = { "8080088","8880888" };
			putchar("8112226"[n % 7]);
			for (int i = 0; i + 1 < (n + 6) / 7; ++i) {
				if (i < 2) putchar(pat[i][n % 7]);
				else putchar('8');
			}
		}

		n -= 1;
		printf(" %c", n % 2 ? '1' : '7');
		for (int i = 0; i < (n - 1) / 2; ++i) putchar('1');
		puts("");
	}
	return 0;
}