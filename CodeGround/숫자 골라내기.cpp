#include <cstdio>
#include <map>
using namespace std;

typedef map<int, int> MI;

MI P;

int main(){
    int T, testCase, N;
    scanf("%d", &testCase);
    for(int T=1; T <= testCase; ++T){
        scanf("%d", &N);
        P.clear();
        int i, ret=0, k, maxN=-1;
        for(i=0; i<N; ++i){
            scanf("%d", &k);
            P[k] += 1;
            if(maxN < k) maxN = k;
        }
        MI::iterator it = P.begin();
        bool first = false;
        for(;it != P.end(); ++it){
            int f=it->first, s=it->second;
            if(s%2){
                if(! first){
                    first = true;
                    ret = f;
                } else {
                    ret ^= f;
                }
            }
        }
        printf("Case #%d\n%d\n", T, ret);
    }
    return 0;
}