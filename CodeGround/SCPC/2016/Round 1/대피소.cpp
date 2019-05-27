#include <bits/stdc++.h>
using namespace std;

#define INF 987987654321LL

typedef long long lld;
typedef pair<lld, lld> ii;

struct iii {
	int w, n, o;
	bool operator < (const iii& p) const {
		if(o == p.o){
			if(w == p.w) return n > p.n;
			return w > p.w;
		}
		return o > p.o;
	}
};

int main(){
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<ii> adj[n];
		while(m--){
			int v, u, w;
			scanf("%d%d%d", &v, &u, &w);
			adj[v-1].push_back(ii(u-1, w));
			adj[u-1].push_back(ii(v-1, w));
		}
		
		vector<lld> cost(n, INF); /* s 로부터 i까지의 최소 비용 */
		vector<int> spot(n, 0);
		priority_queue<iii /*(weight, next, original_exit)*/> q;
		while(k--){
			int u;
			scanf("%d", &u);
			q.push((iii){0, u-1, u});
			cost[u-1] = 0;
			spot[u-1] = u;
		}
		
		while(!q.empty()){
			int pos = q.top().n;
			lld dist = q.top().w;
			int origin = q.top().o;
			q.pop();
			
			for(int i=0; i<adj[pos].size(); ++i){
				ii& next = adj[pos][i]; /* (next, weight) */
				if(dist + next.second >= cost[next.first]) continue;
				q.push((iii){dist+next.second, next.first, origin});
				cost[next.first] = dist+next.second;
				spot[next.first] = origin;
			}
		}
		
		lld costs=0, spots=0;
		for(int i=0; i<n; ++i){
			costs += cost[i];
			spots += spot[i];
		}
		
		printf("Case #%d\n%lld\n%lld\n", tc, costs, spots);
	}
	return 0;
}