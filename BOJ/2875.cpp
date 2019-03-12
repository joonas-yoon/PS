#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, min((n - i) / 2, m - k + i));
    }
    printf("%d\n", ans);

    return 0;
}