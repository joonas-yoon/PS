#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef unsigned long long llu;

bool isPrimeByQewin(llu n){
	// http://qewin.xyz/6191351
	if(n==2 || n==3 || n==5) return true;
	if(n<5 || n%2 == 0 || n%3 == 0 || n%5 == 0) return false;
	int cycle[]={4,2,4,2,4,6,2,6};
	for(int loop=7; loop*loop <= n;){
		for(int d=0; d<8; ++d){
			if(n%loop == 0) return false;
			loop += cycle[d];
		}
	}
	return true;
}

lld interpret(const string& s, lld k){
	lld sum = 0;
	for(int i=0; i<s.length(); ++i)
		sum = sum*k + (s[i]-'0');
	return sum;
}

lld divisor(lld n){
	for(lld i=2; i*i<n; ++i)
		if(n%i == 0) return i;
	return 1;
}

vector<lld> isOk(const string& s){
	vector<lld> ret;
	for(int i=2; i<=10; ++i){
		lld k = interpret(s, i);
		if( isPrimeByQewin(k) || divisor(k) == 1 ) return vector<lld>();
		ret.push_back(divisor(k));
	}
	return ret;
}

int main(){
	int tc, T;
	scanf("%d ", &T);
	for(tc=0; tc<T; ++tc){
		int N, J;
		scanf("%d %d ", &N, &J);
		printf("Case #%d:\n", tc+1);
		
		lld c = 1 + (1LL<<(N-1)), bound = 1LL<<N;
		for(int j = 0; j < J && c < bound; c += 2){
			string bin;
			for(lld n = c; n > 0; n /= 2){
				bin.push_back((n%2)+'0');
			}
			std::reverse(bin.begin(), bin.end());
			
			vector<lld> v = isOk(bin);
			if(v.empty()) continue;
			
			printf("%s ", bin.c_str());
			for(int i=0; i<v.size(); ++i)
				printf("%lld ", v[i]);
			j += 1;
			puts("");
		}
	}
	return 0;
}