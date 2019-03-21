#include <bits/stdc++.h>
using namespace std;

const int MOD = 123456789;

int main() {
    int n;
    scanf("%d", &n);
    bool era[40001] = {};
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (era[i]) continue;
        for (int j = i * i; j <= n; j += i) era[j] = true;
        primes.push_back(i);
    }

    int dp[40001] = {1,};
    for (int i = 0; i < primes.size(); ++i) {
        int p = primes[i];
        for (int j = p; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - p]) % MOD;
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}