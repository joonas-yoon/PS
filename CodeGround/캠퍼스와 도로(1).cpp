#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long lld;
typedef pair<int, int> ii;

void dijkstra(vector<ii> adj[], int start, int n, vector<bool> &isTransfer){
    vector<int> cost(n, INF);
    priority_queue<ii> pq;
    pq.push(ii(0, start)); // {-cost, pos}
    cost[start] = 0;
    while(!pq.empty()){
        int curPos = pq.top().second;
        int curW = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<adj[curPos].size(); ++i){
            int next = adj[curPos][i].first;
            int nextW = cost[curPos] + adj[curPos][i].second;
            if(cost[next] <= nextW) continue;
            cost[next] = nextW;
            pq.push(ii(-nextW, next));
        }
    }
    
    for(int i=0; i<n; i++){
        if(start == i) continue;
        for(int j=0; j<adj[i].size(); ++j){
            isTransfer[i] = isTransfer[i] & (cost[adj[i][j].first] - cost[i] != adj[i][j].second);
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int tc=1; tc<=T; ++tc){
        int n, m;
        scanf("%d %d", &n, &m);
        vector<ii> adj[n];
        while(m--){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u-1].push_back(ii(v-1, w));
            adj[v-1].push_back(ii(u-1, w));
        }
        vector<bool> isTransfer(n, true);
        for(int i=0; i<n; ++i){
            dijkstra(adj, i, n, isTransfer);
        }
        
        int numOfLeafs = 0;
        for(int i=0; i<n; ++i){
            numOfLeafs += isTransfer[i];
        }
        
        printf("Case #%d\n%d ", tc, numOfLeafs);
        for(int i=0; i<n; ++i){
            if(isTransfer[i]) printf("%d ", i+1);
        }
        puts("");
    }
    return 0;
}