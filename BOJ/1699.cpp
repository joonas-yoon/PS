#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 4;
    for (int a = 1; a * a <= n; ++a) {
        if (a * a == n) ans = min(ans, 1);
        for (int b = 1; a * a + b * b <= n; ++b) {
            if (a * a + b * b == n) ans = min(ans, 2);
            for (int c = 1; a * a + b * b + c * c <= n; ++c) {
                if (a * a + b * b + c * c == n) ans = min(ans, 3);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}