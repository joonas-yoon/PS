#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<(n); ++i)
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    int a[101][101];
    scanf("%d", &n);
    FOR(i, n) FOR(j, n) scanf("%d", &a[i][j]);
    int k = 0, r = 0, c = 0;
    FOR(i, n) {
        k += a[i][i];
    }
    FOR(i, n) {
        bool fq[101] = {};
        bool ans = true;
        FOR(j, n) {
            if (fq[a[i][j]]) {
                ans = false;
                break;
            }
            fq[a[i][j]] = true;
        }
        r += ans;
        ans = true;
        memset(fq, 0, sizeof(fq));
        FOR(j, n) {
            if (fq[a[j][i]]) {
                ans = false;
                break;
            }
            fq[a[j][i]] = true;
        }
        c += ans;
    }
    printf("%d %d %d\n", k, n-r, n-c);
}

int main() {
    int T;
    scanf("%d ", &T);
    REP(tc, 1, T + 1) {
        printf("Case #%d: ", tc);
        solve();
    }
    return 0;
}