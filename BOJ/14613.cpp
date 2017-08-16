#include <bits/stdc++.h>
using namespace std;

int main() {
	double win, lose, draw;
	scanf("%lf %lf %lf", &win, &lose, &draw);
	// x판일때 점수가 k일 확률
	double dp[21][3101] = {};
	dp[1][2050] = win;
	dp[1][2000] = draw;
	dp[1][1950] = lose;
	for (int i = 2; i <= 20; ++i) {
		for (int j = 1000; j <= 3000; j += 50) {
			dp[i][j] += dp[i - 1][j - 50] * win;
			dp[i][j] += dp[i - 1][j] * draw;
			dp[i][j] += dp[i - 1][j + 50] * lose;
		}
	}

	double answer[5] = {};
	for (int i = 1000; i <= 3000; i += 50) {
		answer[(i - 1000) / 500] += dp[20][i];
	}
	for (int i = 0; i < 5; ++i) printf("%.8lf\n", answer[i]);
	return 0;
}