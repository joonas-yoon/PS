#include <cstdio>

int main() {
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for (int i = 0; i <= n / a; ++i) {
        for (int j = 0; j <= n / b; ++j) {
            for (int k = 0; k <= n / c; ++k) {
                if (a*i + b * j + c * k == n) {
                    return puts("1"), 0;
                }
            }
        }
    }
    puts("0");
    return 0;
}