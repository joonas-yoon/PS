#include <cstdio>

typedef long long lld;

int gcd(int p, int q) {
    return q ? gcd(q, p%q) : p;
}

lld lcm(int p, int q) {
    return (lld)p * q / gcd(p, q);
}

int main() {
    int n;
    scanf("%d", &n);
    lld a, b = 1;
    bool rot = false;
    for (int i = 0; i < n; ++i) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        if (d) rot = !rot;
        a = lcm(b, x);
        b = a / x * y;
    }
    printf("%d %lld\n", rot, b);
    return 0;
}