#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, a[100001];
int dp[100001][2];

int f(int x, bool sel) {
    if (x >= n) return 0;

    int& res = dp[x][sel];
    if (res != -INF) return res;
    
    res = a[x] + f(x + 1, true);
    if (!sel) res = max(res, f(x + 1, false));
    else res = max(res, a[x]);

    return res;
}

int main() {
    scanf("%d", &n);
    int r = -INF;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i][0] = dp[i][1] = -INF;
        r = max(r, a[i]);
    }

    // there are only negatives
    if (r < 0) return printf("%d\n", r), 0;
    printf("%d\n", f(0, false));

    return 0;
}