#include <cstdio>
bool prime(int n){
    if(n < 2) return false;
    for(int i=2; (long long)i*i<=n; ++i)
        if(n % i == 0) return false;
    return true;
}
int main(){
    int n;
    scanf("%d", &n);
    puts(prime(n) ? "Yes" : "No");
    return 0;
}