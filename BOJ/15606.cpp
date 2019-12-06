#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

lld solve(lld a, lld b, lld c) {
    lld k = min(min(a, b), c);
    return a * a + b * b + c * c + 7 * k;
}

lld naive(lld a, lld b, lld c, lld k) {
    if (k == 0) return solve(a, b, c);
    return max(max(
        naive(a + 1, b, c, k - 1),
        naive(a, b + 1, c, k - 1)),
        naive(a, b, c + 1, k - 1)
    );
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        lld a, b, c, d;
        cin >> a >> b >> c >> d;
        lld ans = max(solve(a + d, b, c), solve(a, b + d, c));
        ans = max(ans, solve(a, b, c + d));
        if (d <= 7) ans = max(ans, naive(a, b, c, d));
        cout << ans << '\n';
    }
    return 0;
}