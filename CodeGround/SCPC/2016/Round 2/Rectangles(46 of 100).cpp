#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long lld;

struct rect {
	int x1, y1, x2, y2;
};

bool isInclude(const rect& p, const rect& q){
	if(p.x1 <= q.x1 && q.x1 < q.x2 && q.x2 <= p.x2)
		return p.y1 <= q.y1 && q.y1 < q.y2 && q.y2 <= p.y2;
	return false;
}

vector<int> adj[5001];

int dp[5001];
int f(int pos){
	int& r = dp[pos];
	if(r != -1) return r;
	r = 1;
	for(int i=0; i<adj[pos].size(); ++i){
		r = max(r, 1 + f(adj[pos][i]));
	}
	return r;
}

int main(){
	setbuf(stdout, NULL);
	
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		
		rect r[k];
		for(int i=0; i<k; ++i){
			scanf("%d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
			adj[i].clear();
		}
		
		for(int i=0; i<k; ++i){
			for(int j=0; j<k; ++j){
				if(i != j && isInclude(r[i], r[j])){
					adj[i].push_back(j);
				}
			}
		}
		
		printf("Case #%d\n", tc);
		
		int ans = 0;
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<k; ++i){
			ans = max(ans, f(i));
		}
		printf("%d\n", ans);
	}
	
	return 0;
}