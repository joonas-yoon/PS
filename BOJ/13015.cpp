#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 1; j < n - abs(i - n + 1); ++j) putchar(' ');

        if (i == 0 || i == 2 * n - 2) {
            for (int j = 0; j < n; ++j) putchar('*');
        } else {
            putchar('*');
            for (int j = 2; j < n; ++j) putchar(' ');
            putchar('*');
        }

        for (int j = 1; j < abs(2 * (n - i - 1)); ++j) putchar(' ');

        if (i == 0 || i == 2 * n - 2) {
            for (int j = 0; j < n; ++j) putchar('*');
        } else {
            if (i != n - 1) putchar('*');
            for (int j = 2; j < n; ++j) putchar(' ');
            putchar('*');
        }
        puts("");
    }
    return 0;
}