#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef pair<int, int> ii;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char s[1001][1001];
    for(int i=0; i<n; ++i) scanf("%s ", s[i]);
    
    vector<vector<int> > dist(1001, vector<int>(1001, INF));
    queue<ii> q;
    while(k--){
        int r, c;
        scanf("%d %d", &r, &c);
        q.push(ii(r-1, c-1));
        dist[r-1][c-1] = 0;
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int d = dist[y][x];
        q.pop();
        
        for(int i=0; i<4; ++i){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(s[ny][nx] == '#' || dist[ny][nx] <= d+1) continue;
            dist[ny][nx] = d + 1;
            q.push(ii(ny, nx));
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(s[i][j] != '#') ans += dist[i][j];
        }
    }
    printf("%d", ans);
    
    return 0;
}