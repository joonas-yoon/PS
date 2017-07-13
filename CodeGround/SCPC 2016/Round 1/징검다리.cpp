#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MOD 1000000009

typedef long long lld;

int dp[50001][101], k;
bool mine[50001];
int f(int pos, int jump){
	if(pos < 0 || mine[pos]) return 0;
	if(pos == 0) return 1;
	
	int& r = dp[pos][jump];
	if(r != -1) return r;
	
	r = 0;
	for(int i=1; pos-i >= 0 && i<=k; ++i){
		if(i == jump) continue;
		r = (r + f(pos-i, i)) % MOD;
	}
	
	return r;
}

int main(){
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc){
		int n, l;
		memset(mine, false, sizeof(mine));
		memset(dp, -1, sizeof(dp));
		scanf("%d %d %d", &n, &k, &l);
		for(int i=0; i<l; ++i){
			int p;
			scanf("%d", &p);
			mine[p] = true;
		}
		printf("Case #%d\n%d\n", tc, f(n, 0));
	}
	return 0;
}