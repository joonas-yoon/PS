#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    lld lo = 0, hi = 1000000000LL * (lld)m;
    while (lo <= hi) {
        lld mid = (lo + hi) / 2LL;

        lld sum = 0;
        for (int i = 0; i < n; ++i) sum += mid / a[i];

        if (sum >= m)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    printf("%lld\n", lo);

    return 0;
}