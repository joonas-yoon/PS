#include <cstdio>
#include <cstdlib>

int A[101][101], B[101][101];

int main(){
    int N, M, K, i, j, k;
    scanf("%d %d", &N, &M);
    
    for(i=0; i<N; ++i)
        for(j=0; j<M; ++j)
            scanf("%d", &A[i][j]);
    
    scanf("%d %d", &M, &K);
    for(i=0; i<M; ++i)
        for(j=0; j<K; ++j)
            scanf("%d", &B[i][j]);
    
    for(i=0; i<N; ++i){
        for(k=0; k<K; ++k){
            int r=0;
            for(j=0; j<M; ++j)
                r += A[i][j]*B[j][k];
            printf("%d ", r);
        }
        puts("");
    }
    
    return 0;
}