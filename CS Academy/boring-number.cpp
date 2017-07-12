#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    double mean = (sum + 1e-12)/n, diff = 987654321;
    int idx = 0;
    for(int i=0; i<n; ++i){
        if( diff > 1e-8 + abs(mean - (double)a[i]) ){
            diff = abs(mean - (double)a[i]);
            idx = i+1;
        }
    }
    printf("%d", idx);
    return 0;
}