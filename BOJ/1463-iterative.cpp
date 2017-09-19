#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main(){
	int i, n;
	scanf("%d", &n);
	dp[2] = dp[3] = 1;
	for(i=4; i <= n; ++i){
		dp[i] = dp[i-1] + 1;
		if(i%3==0) dp[i] = min(dp[i], dp[i/3] + 1);
		if(i%2==0) dp[i] = min(dp[i], dp[i/2] + 1);
	}
	printf("%d", dp[n]);
	return 0;
}