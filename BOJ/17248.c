#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int t = 0, speed = z;
        while (x < y) {
            x += speed;
            t++;
            speed += z;
        }
        printf("%d\n", t);
    }
    return 0;
}