#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>
#define gets(s) gets_s(s)
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {-1, 0, 1, 0};

int main() {
    fastio();

    int T;
    cin >> T;
    FOR(tc, T) {
        cout << "Case #" << tc + 1 << '\n';

        int n;
        cin >> n;
        vector<int> a(n);
        FOR(i, n) cin >> a[i];

        int m = 0;
        vector<bool> v(n);
        FOR(p, n) {
            v[p] = m < a[p];
            m = max(m, a[p]);
        }

        m = INF;
        for (int p = n - 1; p >= 0; --p) {
            v[p] = v[p] && (a[p] < m);
            m = min(m, a[p]);
        }

        int ans = 0;
        FOR(i, n)
            ans += v[i];
        cout << ans << '\n';
    }

    return 0;
}