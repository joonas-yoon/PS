#include <cstdio>

typedef long long lld;

int main() {
    lld three[40] = {};
    three[0] = 1LL;
    for (int i = 1; i < 40; ++i) {
        three[i] = three[i - 1] * 3;
    }

    lld n;
    scanf("%lld", &n);
    
    if (n == 0){
        puts("NO");
        return 0;
    }
    
    for (int i = 39; i >= 0; --i) {
        if (n >= three[i]) {
            n -= three[i];
        }
    }
    puts(n == 0 ? "YES" : "NO");

    return 0;
}