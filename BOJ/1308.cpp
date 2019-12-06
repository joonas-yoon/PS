#include <cstdio>

bool isLeap(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    if (year % 400 == 0) return true;
    return false;
}

int mon[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int days(int y, int m, int d) {
    int r = 0;
    for (int i = 0; i < y; ++i) {
        r += 365 + isLeap(i);
    }
    for (int i = 0; i + 1 < m; ++i) {
        if (i == 1) r += isLeap(y);
        r += mon[i];
    }
    return r + d;
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
    if (y2 - y1 >= 1000 && days(0, m1, d1) <= days(0, m2, d2)) return puts("gg"), 0;
    int r1 = days(y1, m1, d1);
    int r2 = days(y2, m2, d2);
    printf("D-%d\n", r2 - r1);
    return 0;
}