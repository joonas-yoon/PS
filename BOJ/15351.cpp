#include <cstdio>

int main(){
	int T;
	scanf("%d ", &T);
	while(T--){
		char s[50]={};
		gets(s);
		int r = 0;
		for(int i=0; s[i]; ++i){
			if(s[i] != ' ') r += s[i] - 'A' + 1;
		}
		if(r == 100) puts("PERFECT LIFE");
		else printf("%d\n", r);
	}
	return 0;
}