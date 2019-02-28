#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define fastio() ios::ios_base::sync_with_stdio(false); setbuf(stdout, 0); cin.tie(false)

map<string, int> poke;
string index[1000000];

int main(){
    fastio();
    
	int i, N, M;
	cin >> N >> M;
	string s;
	for(i=1; i <= N; ++i) cin >> s, poke[s]=i, index[i]=s;
	for(i=0; i < M; ++i){
		cin >> s;
		if(s[0] >= '0' && s[0] <= '9'){
			int t = atoi(s.c_str());
			cout<< index[t] <<'\n';
		}
		else {
			cout<< poke[s] <<'\n';
		}
	}
	return 0;
}