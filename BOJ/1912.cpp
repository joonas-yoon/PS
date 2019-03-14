#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    int s = 0, m = -INF;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s += x;
        m = max(m, s);
        if (s < 0) s = 0;
    }
    printf("%d\n", m);
    return 0;
}