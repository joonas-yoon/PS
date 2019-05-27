#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long lld;

lld a[1000][1000];

int main() {
    int n;
    scanf("%d", &n);
    lld h = 0, total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &a[i][j]);
            h = max(h, a[i][j]);
            total += a[i][j];
        }
    }

    lld l = 0, goal = total / 2 + (total % 2);
    while (l <= h) {
        lld mid = (l + h) / 2;

        lld sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += min(mid, a[i][j]);
            }
        }
        
        if (sum < goal) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    printf("%lld\n", l);

    return 0;
}