#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	map<int, int> self;
	int i, j;
	for(i=1; i <= 10000; ++i){
		int k = i;
		while(k > 0 && k < 10000)
		{
			char buf[100]={};
			sprintf(buf, "%d", k);
			int l = strlen(buf), sum = k;
			for(j=0; j < l; ++j){
				sum += buf[j]-'0';
			}
			if(self[sum]) break;
			k = sum;
			self[sum]++;
		}
	}
	for(i=1; i <= 9993; ++i){
		if(self[i]==0) cout<< i <<'\n';
	}
	return 0;
}