#include <cstdio>

typedef long long lld;

lld dp[31][31];

lld C(int n, int k) {
    if (k == 0 || n == k) return 1;
    lld& ret = dp[n][k];
    if (ret != 0) return ret;
    return ret = C(n - 1, k - 1) + C(n - 1, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld\n", C(n - 1, k - 1));
    return 0;
}