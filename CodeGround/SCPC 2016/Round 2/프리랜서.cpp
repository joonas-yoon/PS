#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long lld;

int main(){
	int n, T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc){
		scanf("%d", &n);
		int a[2][10001];
		for(int k=0; k<2; ++k){
			for(int i=0; i<n; ++i) scanf("%d", &a[k][i]);
		}
		
		int dp[2][10005]={};
		for(int i=2; i<n+2; ++i){
			dp[0][i] = max(dp[0][i-1], dp[1][i-1]) + a[0][i-2];
			dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + a[1][i-2];
		}
		printf("Case #%d\n", tc);
		printf("%d\n", max(dp[0][n+1], dp[1][n+1]));
	}
	
	return 0;
}