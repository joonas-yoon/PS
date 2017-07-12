#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    int m = INF, M = -1;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        m = min(m, a[i]);
        M = max(M, a[i]);
    }
    
    // contains index
    vector<int> lo, hi;
    for(int i=0; i<n; ++i){
        if(m == a[i]) lo.push_back(i);
        if(M == a[i]) hi.push_back(i);
    }
    
    int ans = INF;
    for(auto& x : lo){
        int idx = lower_bound(hi.begin(), hi.end(), x) - hi.begin();
        if(idx < hi.size()) ans = min(ans, abs(x - hi[idx]) + 1);
        if(idx - 1 >= 0) ans = min(ans, abs(x - hi[idx-1]) + 1);
    }
    printf("%d\n", ans);
    
    return 0;
}