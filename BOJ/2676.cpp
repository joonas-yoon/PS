#include <bits/stdc++.h>
using namespace std;

int r(int n, int m){
	if(n < m) swap(n, m);
	if(n < 3) return 1;
	return m * (n - m) + 1;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", r(n, m));
	}
	return 0;
}