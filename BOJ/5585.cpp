#include <cstdio>

int main() {
    int n, ans = 0, coin[] = {500,100,50,10,5,1};
    scanf("%d", &n);
    n = 1000 - n;
    for (int i = 0; i < 6 && n > 0; i++) {
        ans += n / coin[i];
        n %= coin[i];
    }
    printf("%d\n", ans);
    return 0;
}