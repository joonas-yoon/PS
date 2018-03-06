#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	long long i, N, k, ret=1;
	scanf("%lld", &N);
	for(i=2; i<=N; ++i){
		k = i;
		while(k%10==0) k/=10;
		ret *= k;
		while(ret%10==0) ret/=10;
		ret %= 10000000000000;
	}
    ret %= 100000;
    
	if(N < 10) return printf("%lld\n", ret), 0;
	
	char buf[6]={};
	sprintf(buf, "%lld", ret);
	int len = strlen(buf);
	for(int i=0; i<5-len; ++i) putchar('0');
	puts(buf);
	
	return 0;
}