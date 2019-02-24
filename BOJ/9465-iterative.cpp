#include <bits/stdc++.h>
using namespace std;

int a[2][100001];
int dp[3][100001];

int main() {
    int T;
    scanf("%d ", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        }

        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            dp[0][i] = max(dp[0][i + 1], max(dp[1][i + 1], dp[2][i + 1])); // 안 고르는 경우
            dp[1][i] = max(dp[0][i + 1], dp[2][i + 1]) + a[0][i];
            dp[2][i] = max(dp[0][i + 1], dp[1][i + 1]) + a[1][i];
        }

        printf("%d\n", max(max(dp[0][0], dp[1][0]), dp[2][0]));
    }

    return 0;
}