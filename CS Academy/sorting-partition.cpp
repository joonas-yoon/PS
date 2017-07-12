#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), right(n+1, INF);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    
    for (int i = n-1; i >= 0; --i) {
        right[i] = min(right[i+1], v[i]);
    }

    int answer = 0, m = v.front();
    for (int i = 0; i < n; ++i) {
        m = max(m, v[i]);
        answer += m <= right[i+1];
    }
    printf("%d", answer);
    return 0;
}
