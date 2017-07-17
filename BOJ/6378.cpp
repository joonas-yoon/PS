#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	char str[10000]={};
	while(gets(str)){
		if(!strcmp(str, "0")) break;
		int i, len=strlen(str), s=str[0]-'0';
		while( len > 1 ){
			for(s=i=0; i < len; ++i) s += (str[i]-'0');
			sprintf(str,"%d",s);
			len = strlen(str);
		}	
		printf("%d\n", s);
	}
	return 0;
}