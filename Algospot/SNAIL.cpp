#include <bits/stdc++.h>
using namespace std;

double dp[1001][1001];

double snail(int height, int day){
	if(day < 0) return 0;
	if(height <= 0) return 1;
	double& r = dp[height][day];
	if(r != -1) return r;
	return r = 0.75 * snail(height-2, day-1) + 0.25 * snail(height-1, day-1);
}

int main(){
	int n, m, T;
	scanf("%d", &T);
	fill(&dp[0][0], &dp[1000][1000], -1.0);
	while(T--){
		scanf("%d %d", &n, &m);
		printf("%.9lf\n", snail(n, m));
	}
	return 0;
}