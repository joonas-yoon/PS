#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int cost[16][16];
int dp[1 << 16]; // i인 상태를 만드는 최소 비용

int main() {
	int n, p;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d ", &cost[i][j]);

	char power[17];
	scanf("%s %d", power, &p);

	for (int i = 0; i < (1 << n); ++i) dp[i] = INF;

	int bit = 0;
	for (int i = 0; power[i]; ++i)
		bit |= (power[i] == 'Y') << i;
	dp[bit] = 0;

	for (int b = bit; b < (1 << n); ++b) {
		for (int i = 0; i < n; ++i) {
			if (b & (1 << i)) continue;
			int& next = dp[b | (1 << i)];
			for (int j = 0; j < n; ++j) {
				if (b & (1 << j)) {
					next = min(next, dp[b] + cost[j][i]);
				}
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0;
		for (int k = i; k > 0; k /= 2) cnt += (k & 1) != 0;
		if (cnt >= p) answer = min(answer, dp[i]);
	}
	printf("%d", answer < INF ? answer : -1);

	return 0;
}