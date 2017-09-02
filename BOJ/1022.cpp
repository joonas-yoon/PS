#include <bits/stdc++.h>
using namespace std;

int len(int n){
	int r = 0;
	for(;n>0; n/=10) ++r;
	return r;
}

int main() {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	int digit = 1;
	int x=0, y=0, d=0, num=1, cnt=(r2-r1+1)*(c2-c1+1);
	int dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, k = 1;
	int ans[51][51] = {};
	while(cnt > 0){
		for(int j=0; j<2; ++j){
			for(int i=0; i<k; ++i){
				if(r1 <= y && y <= r2 && c1 <= x && x <= c2){
					ans[y-r1][x-c1] = num;
					digit = max(digit, len(num));
					cnt--;
				}
				x += dx[d];
				y += dy[d];
				num++;
			}
			d = (d+1)%4;
		}
		++k;
	}

	char format[10]={};
	sprintf(format, "%%%dd ", digit);
	for(int i=r1; i<=r2; ++i){
		for(int j=c1; j<=c2; ++j)
			printf(format, ans[i-r1][j-c1]);
		puts("");
	}
	return 0;
}