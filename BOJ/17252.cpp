#include <cstdio>

int main() {
    int three[20];
    three[0] = 1;
    for (int i = 1; i < 20; ++i) {
        three[i] = three[i - 1] * 3;
    }

    int n;
    scanf("%d", &n);
    
    if (n == 0){
        puts("NO");
        return 0;
    }
    
    for (int i = 19; i >= 0; --i) {
        if (n >= three[i]) {
            n -= three[i];
        }
    }
    puts(n == 0 ? "YES" : "NO");

    return 0;
}