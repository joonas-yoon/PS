#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)
#define FOR(i, n) for(int i=0;i<(n);++i)
#define all(v) (v).begin(), (v).end()
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))
#define ABS(n) ((n)<0?-(n):(n))

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dy[] = { 1,-1,1,-1 };
const int dx[] = { 1,1,-1,-1 };

int n, a[1000001];

struct paint {
    int height, from;
};

int main() {
    fastio();

    int w;
    lld sum = 0;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    deque<paint> dq;
    for (int i = 0; i < w; ++i) {
        while (!dq.empty() && dq.back().height > a[i])
            dq.pop_back();
        dq.push_back({ a[i], i });
    }

    lld area = 0;
    int lastHeight = dq.front().height;
    int cnt = 0, last = 0;
    for (int i = w; i <= n; ++i) {
        while (!dq.empty() && dq.back().height > a[i])
            dq.pop_back();
        dq.push_back({ a[i], i });

        if (lastHeight != dq.front().height) {
            cnt += (i - last - 1) / w + 1;
            area += (i - last + 0LL) * lastHeight;
            last = i; // 칠해지지 않은 장소
            lastHeight = dq.front().height;
        }

        while (!dq.empty() && dq.front().from + w <= i) {
            int cur = dq.front().from + 1;
            dq.pop_front();
            if (lastHeight != dq.front().height) {
                cnt += (cur - last - 1) / w + 1;
                area += (cur - last + 0LL) * lastHeight;
                last = cur; // 칠해지지 않은 장소
                lastHeight = dq.front().height;
            }
        }
    }

    printf("%lld\n%d\n", max(0LL, sum - area), cnt);

    return 0;
}