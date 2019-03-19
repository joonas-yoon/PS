#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

priority_queue<int> q;

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
        q.push(-a[i]);
    }
    
    int order = 0, prev = -1;
    while (!q.empty()) {
        int cur = -q.top();
        q.pop();

        // 중복 제거
        if (prev == cur) continue;
        prev = cur;

        if (++order == n) {
            return printf("%d\n", cur), 0;
        }

        for (int i = 0; i < k; ++i) {
            lld next = (lld)cur * a[i];
            if (next >= (1LL << 31)) continue;
            q.push(-next);
        }
    }

    return 0;
}