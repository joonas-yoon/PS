#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld n, ans;
bool dig[10];
int length;

void solve(int sel, lld val = 0) {
    if (sel >= length) {
        if (abs(n - ans) > abs(n - val)) {
            ans = val;
        }
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (dig[i]) continue;
        dig[i] = true;
        solve(sel + 1, val * 10LL + i);
        dig[i] = false;
    }
}

int main() {
    ans = 9876543210LL;

    scanf("%lld", &n);

    length = 0;
    for (int i = n; i > 0; i /= 10) length++;

    solve(0, 0);

    printf("%lld\n", ans);

    return 0;
}