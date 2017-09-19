#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

int dp[5001];

int solve(int cur){
	if(cur == 0) return 0;
	if(cur < 0) return INF;
	int& ret = dp[cur];
	if( ret != -1 ) return ret;
    ret = INF;
	return ret = 1 + min(solve(cur-5), solve(cur-3));
}

int main(void) {
	int N;
	scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
	int res = solve(N);
    printf("%d\n", res < INF ? res : -1);
	return 0;
}