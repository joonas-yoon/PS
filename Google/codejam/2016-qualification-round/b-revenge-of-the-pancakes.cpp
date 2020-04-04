#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

#define INF 987654321

int main(){
	int i, T;
	scanf("%d ", &T);
	for(int tc=0; tc<T; ++tc){
		string s;
		cin >> s;
		string r(1, s[0]);
		for(i=1; i<s.length(); ++i){
			if(r.back() != s[i]) r.push_back(s[i]);
		}
		int ret = 0;
		for(i=0; i<r.length(); ++i){
			if(r[i]=='-') ret += 2;
		}
		printf("Case #%d: %d\n", tc+1, ret-(r[0]=='-'));
	}
	return 0;
}