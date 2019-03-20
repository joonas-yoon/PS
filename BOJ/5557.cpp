#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int n;
vector<int> v;

lld dp[101][21];

lld solve(int k, int sum) {
    if (sum < 0 || sum > 20) return 0;
    if (k == n - 1) return sum == v[n - 1];

    lld& ret = dp[k][sum];
    if (ret != -1) return ret;

    ret = 0;
    ret += solve(k + 1, sum + v[k]);
    ret += solve(k + 1, sum - v[k]);
    return ret;
}

int main() {
    memset(dp, -1LL, sizeof(dp));

    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

    printf("%lld\n", solve(1, v[0]));

    return 0;
}