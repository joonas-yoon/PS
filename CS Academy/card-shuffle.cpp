#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(int i=0; i<n; ++i) a[i] = i+1;
    if( n % 2 == 0 ) k %= 4;
    else k %= 2;
    vector<int> b = a;
    while(k--){
        for(int i=0; i<n; i+=2){
            b[i] = a[i+1];
        }
        for(int i=0; i<n; i+=2){
            b[n-1-i] = a[i];
        }
        a = b;
    }
    for(int i=0; i<n; ++i) printf("%d ", b[i]);
    return 0;
}