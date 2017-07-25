#include <cstdio>
#include <cstring>

#define INF 987654321

inline int min(int a, int b){return a<b?a:b;}

int sync_n[10]={3, 4, 4, 5, 5, 4, 3, 5, 5, 5};
int sync[10][5]={
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

int a[16];

bool isFinish(){
	for(int i=0; i<16; ++i) if(a[i]!=12) return false;
	return true;
}

void push(int id, int tog){
	for(int i=0; i<sync_n[id]; ++i){
		int& e = a[sync[id][i]];
		e += 3 * tog;
		if(e < 3) e = 12;
		else if(e > 12) e -= 12;
	}
}

int f(int pos){
	if(pos == 10){
		if( isFinish() ) return 0;
		return INF;
	}
	
	int i, k, r = INF;
	for(i=0; i<4; ++i){
		r = min(r, i + f(pos+1));
		push(pos, 1);
	}
	return r;
}

int main(){
	int i, T;
	scanf("%d ", &T);
	while(T--){
		for(i=0; i<16; ++i) scanf("%d", &a[i]);
		int ans = f(0);
		printf("%d\n", ans<INF ? ans:-1);
	}
	return 0;
}