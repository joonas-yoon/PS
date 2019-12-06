#include <cstdio>

typedef long long lld;

#define MOD 16769023

// a ^ p
lld pw(int a, int p) {
    if (p == 0) return 1;
    if (p == 1) return a % MOD;
    lld half = pw(a, p / 2);
    lld sqr = (half * half) % MOD;
    if (p & 1) return (sqr * (a % MOD)) % MOD;
    return sqr;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", pw(2, (n + 1) / 2));
    return 0;
}