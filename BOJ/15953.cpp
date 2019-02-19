#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	vector<int> x(100, 0), y(64, 0);
	int first[]={500,300,200,50,30,10};
	for(int i=0, idx=0; i<6; ++i){
		for(int j=0; j<=i; ++j) x[idx++] = first[i];
	}
	for(int i=0, idx=0; i<5; ++i){
		for(int j=0; j<(1<<i); ++j) y[idx++] = 512 / (1<<i);
	}
	
	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", (x[a-1] + y[b-1]) * 10000);
	}
	return 0;
}