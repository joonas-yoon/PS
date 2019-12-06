#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long lld;

int main() {
    int n, a[20] = {};
    lld w;
    scanf("%d %lld", &n, &w);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    lld dp[20] = {w, 0,};
    for (int i = 1; i <= n; ++i) {
        w = dp[i] = max(dp[i], w);
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] < a[j]) {
                lld c = w / a[i];
                dp[j] = max(dp[j], dp[i] + c * (a[j] - a[i]));
            }
        }
    }
    printf("%lld\n", w);
    return 0;
}