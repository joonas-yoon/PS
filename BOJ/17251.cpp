#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000];
int L[1000000];
int R[1000000];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    
    for(int i=0, m=0; i<n; ++i){
        m = std::max(m, a[i]);
        L[i] = m;
    }
    for(int i=n-1, m=0; i>=0; --i){
        m = std::max(m, a[i]);
        R[i] = m;
    }
    
    int r = 0, b = 0;
    for(int i=0; i<n; ++i){
        r += L[i] > R[i];
        b += L[i] < R[i];
    }
    
    if(r == b) putchar('X');
    else if(r > b) putchar('R');
    else putchar('B');
    
    return 0;
}