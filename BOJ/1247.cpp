#include <cstdio>
#include <cstdlib>
int main(){
	int T=3, N;
	while(T--){
		long double sum = 0, t;
		scanf("%d", &N);
		while(N--){
			scanf("%Lf", &t);
			sum += t;
		}
		if(sum < 0) puts("-");
		else if(sum > 0) puts("+");
		else puts("0");
	}
	return 0;
}