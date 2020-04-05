#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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

bool overlapped(ii& a, ii& b) {
    return a.first <= b.first && b.first < a.second;
}

struct schedule {
    ii range;
    int idx;
    bool operator < (const schedule& s) {
        if (range == s.range) return idx < s.idx;
        return range < s.range;
    }
};

void solve() {
    int n;
    scanf("%d", &n);
    vector<schedule> a;
    FOR(i, n) {
        int s, e;
        scanf("%d %d", &s, &e);
        a.push_back({ ii(s, e), i });
    }
    std::sort(all(a));

    priority_queue<ii> q; // (-end, start)
    FOR(i, n) {
        int start = a[i].range.first, end = a[i].range.second;
        while (!q.empty() && -q.top().first <= start) q.pop();
        q.push(ii(-end, start));
        if (q.size() > 2) {
            puts("IMPOSSIBLE");
            return;
        }
    }

    vector<bool> isCam(n);
    isCam[a[0].idx] = true;
    REP(i, 1, n) {
        bool overlap = overlapped(a[i - 1].range, a[i].range);
        isCam[a[i].idx] = isCam[a[i - 1].idx] ^ overlap;
    }
    FOR(i, n) putchar(isCam[i] ? 'C' : 'J');
    puts("");
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