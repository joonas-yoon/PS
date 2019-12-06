#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int n;
int a[(1<<21)+1];

int f(int pos){
    int l = 2 * pos + 1;
    int r = l + 1;
    // is leaf
    if(l > n || r > n) return a[pos];
    
    int lsum = f(l), rsum = f(r);
    if(lsum < rsum){
        a[l] += rsum - lsum;
    }
    else if(lsum > rsum){
        a[r] += lsum - rsum;
    }
    
    return a[pos] + max(lsum, rsum);
}

int main(){
    int k;
    scanf("%d", &k);
    n = (1<<(k+1))-1-1;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    f(0);
    int ans = 0;
    for(int i=1; i<=n; ++i) ans += a[i];
    printf("%d", ans);
    return 0;
}