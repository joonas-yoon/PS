#include <cstdio>
#include <algorithm>
using namespace std;

static int t[1000001], n;

// [l, r)
int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

void update(int pos, int val) {
    t[pos + n] = val;
    for (pos += n; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
}

int a[500001];
int b[500001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    std::sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        int rank = std::lower_bound(b, b+n, a[i]) - b;
        int countAfterMe = query(rank + 1, n);
        printf("%d\n", countAfterMe + 1);
        update(rank, 1);
    }

    return 0;
}
