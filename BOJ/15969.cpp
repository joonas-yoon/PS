#include <cstdio>
#include <algorithm>

int main() {
    int n, x, a = 0, b = 9999;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a = std::max(a, x);
        b = std::min(b, x);
    }
    printf("%d\n", a - b);
    return 0;
}