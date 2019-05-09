#include <cstdio>
#include <algorithm>
using namespace std;

int trol[9];
int ans[7];

void solve(int cur, int sel = 0, int sum = 0) {
    if (sel == 7 && sum == 100) {
        for (int i = 0; i < 7; ++i) printf("%d\n", ans[i]);
        exit(0);
        return;
    }
    if (cur > 9 || sel > 7 || sum > 100) return;

    ans[sel] = trol[cur];
    solve(cur + 1, sel + 1, sum + trol[cur]);
    solve(cur + 1, sel, sum);
}

int main() {
    for (int i = 0; i < 9; ++i) scanf("%d", &trol[i]);

    sort(trol, trol + 9);
    solve(0);

    return 0;
}