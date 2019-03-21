#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

struct line {
    int s, e;
    bool operator < (const line& l) {
        if (s == l.s) return e < l.e;
        return s < l.s;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<line> v(n);
    for (int i = 0; i < n; ++i) {
        int s, e;
        scanf("%d %d", &s, &e);
        if (s > e) swap(s, e);
        v[i] = {s, e};
    }
    sort(all(v));

    int ans = 0, s = v[0].s, e = v[0].e;
    for (int i = 1; i < n; ++i) {
        if (v[i].e <= e) continue;
        if (v[i - 1].e < v[i].s) {
            ans += e - s;
            s = v[i].s;
        }
        e = v[i].e;
    }
    ans += e - s;
    printf("%d\n", ans);
    return 0;
}