#include <cstdio>
#include <algorithm>

int main(){
    int T, testCase, N, K, i;
    scanf("%d", &testCase);
    for(int T=1; T <= testCase; ++T){
        scanf("%d %d", &N, &K);
        int a[200001], ret=0;
        for(i=0; i<N; ++i) scanf("%d", &a[i]);
        std::sort(a, a+N);
        for(i=0; i<K; ++i) ret += a[N-i-1];
        printf("Case #%d\n%d\n", T, ret);
    }
    return 0;
}