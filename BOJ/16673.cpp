#include <cstdio>

typedef long long lld;

int main() {
    lld c, k, p;
    scanf("%lld %lld %lld", &c, &k, &p);
    lld ans = 0;
    for (int n = 1; n <= c; ++n) {
        ans += k * n + p * n * n;
    }
    printf("%lld\n", ans);

    return 0;
}