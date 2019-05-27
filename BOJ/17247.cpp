#include <cstdio>

int abs(int n){
    return n < 0 ? -n : n;
}

int main(){
    int i, j, k, n, m;
    scanf("%d %d", &n, &m);
    int x = -1, y;
    for(i=0; i<n; ++i){
        for(j=0; j<m; ++j){
            scanf("%d", &k);
            if(k == 1){
                if(x == -1) x = i, y = j;
                else {
                    printf("%d\n", abs(i - x) + abs(j - y));
                    return 0;
                }
            }
        }
    }
    return 0;
}