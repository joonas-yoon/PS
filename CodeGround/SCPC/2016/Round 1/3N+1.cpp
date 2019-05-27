#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long lld;

int sizeOfCycle(int n){
	int len = 0;
	while(n>1){
		if(n&1) n = 3*n + 1;
		else n /= 2;
		++len;
	}
	return len;
}

void answer(int k){
	bool mini = false;
	int m = -1;
	for(int f=1; f<=5000; ++f){
		int len = sizeOfCycle(f);
		if(len != k) continue;
		printf("%d ", f);
		break;
	}
	printf("%llu\n", 1LL<<k);
}

int main(){
	setbuf(stdout, NULL);
	
	int T, k;
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc){
		scanf("%d", &k);
		printf("Case #%d\n", tc);
		answer(k);
	}
	return 0;
}