#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

typedef long long lld;
typedef pair<int, int> ii;

const int DY[]={-1, 0, 1, 0};
const int DX[]={ 0, 1, 0,-1};

int main(){
	int T, i, j, h, w;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d ", &w, &h);
		char s[1001][1001];
		for(i=0; i<h; ++i) scanf("%s ", s[i]);
		
		queue<ii> q;
		int startX, startY=0;
		int dist[1001][1001];
		for(i=0; i<h; ++i){
			for(j=0; j<w; ++j){
				dist[i][j] = INF;
				if(s[i][j] == '@'){
					startX = j;
					startY = i;
				} else if(s[i][j] == '*'){
					q.push({i, j});
					dist[i][j] = 0;
				}
			}
		}
		
		int d = 0;
		while(!q.empty()){
			int qs, qsize = q.size();
			for(qs=0; qs<qsize; ++qs){
				ii cur = q.front();
				q.pop();
				for(i=0; i<4; ++i){
					int dy = cur.first+DY[i], dx = cur.second+DX[i];
					if(dy<0 || dx<0 || dy>=h || dx>=w || s[dy][dx]!='.' || dist[dy][dx]<=d+1) continue;
					q.push({dy, dx});
					dist[dy][dx] = d+1;
				}
			}
			d += 1;
		}
		
		d = 0;
		q.push({startY, startX});
		dist[startY][startX] = 0;
		bool find = false;
		while(!q.empty()){
			int qs, qsize = q.size();
			for(qs=0; qs<qsize; ++qs){
				ii cur = q.front();
				q.pop();
				
				if(cur.first == 0 || cur.first == h-1 || cur.second == 0 || cur.second == w-1){
					find = true;
					break;
				}
				
				for(i=0; i<4; ++i){
					int dy = cur.first+DY[i], dx = cur.second+DX[i];
					if(dy<0 || dx<0 || dy>=h || dx>=w || s[dy][dx]!='.' || dist[dy][dx]<=d+1) continue;
					q.push({dy, dx});
					dist[dy][dx] = d+1;
				}
			}
			if(find) break;
			d += 1;
		}
		
		if(find) printf("%d\n", d+1);
		else puts("IMPOSSIBLE");
	}
			
	return 0;
}