#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    int primes = 0;
    for(int i=1; i*i<=n; ++i){
        if( n % i == 0 ){
            primes += (n % i == 0);
            primes += (i != n / i);
        }
    }
    printf("%d\n", primes - 1);
    return 0;
}