#include <bits/stdc++.h>
using namespace std;

int n;
int h[8], w[8];

char solve(int cur) {
    if (cur >= n) return 0;
    if (h[cur] <= 0) return solve(cur + 1);

    char ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cur == i || h[i] <= 0) continue;
        h[cur] -= w[i];
        h[i] -= w[cur];
        char br = (h[cur] <= 0) + (h[i] <= 0);
        ans = max(ans, (char)(br + solve(cur + 1)));
        h[i] += w[cur];
        h[cur] += w[i];
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &h[i], &w[i]);
    }

    printf("%d\n", solve(0));

    return 0;
}