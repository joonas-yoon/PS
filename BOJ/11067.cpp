#include <bits/stdc++.h>
using namespace std;

struct cafe {
	int y, x;
};

bool asce(const cafe& a, const cafe& b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main(){
	int T, n, k, i, j, m;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		cafe a[100002]={};
		a[0]={0,-1};
		for(i=1; i<=n; ++i) scanf("%d %d", &a[i].x, &a[i].y);
		std::sort(a, a+n+1, asce);
		for(i=1; i<=n;){
			for(j=i+1; j<=n && a[i].x == a[j].x; ++j);
			if(a[i-1].y != a[i].y){
				i += i==0;
				std::reverse(a+i, a+j);
			}
			i = j;
		}
		
		scanf("%d", &m);
		while(m--){
			scanf("%d", &k);
			printf("%d %d\n", a[k].x, a[k].y);
		}
	}
	return 0;
}
