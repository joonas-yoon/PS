#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long lld;

int main() {
    int n, a[20];
    lld w;
    scanf("%d %lld", &n, &w);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i]) {
            lld c = w / a[i - 1];
            w += (a[i] - a[i - 1]) * c;
        }
    }
    printf("%lld\n", w);
    
    return 0;
}