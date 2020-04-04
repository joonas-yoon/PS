#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

#define INF 987654321

// string digit[]={"0","1","2","3","4","5","6","7","8","9"};
string sum(int& bit, string &s, string &p){
	int slen = s.length(), plen = p.length();
	int i, j, cr = 0;
	string r = "";
	for(i=j=0; i<slen || j<plen; ++i, ++j){
		if(i<slen) cr += s[i]-'0';
		if(j<plen) cr += p[j]-'0';
		r.push_back(cr%10 + '0');
		bit |= 1<<(cr%10);
		cr /= 10;
	}
	if(cr > 0){
		r.push_back(cr%10 + '0');
		bit |= 1<<(cr%10);
	}
	return r;
}

int main(){
	int T;
	cin >> T;
	for(int tc=0; tc<T; ++tc){
		string s;
		cin >> s;
		printf("Case #%d: ", tc+1);
		if(s.compare("0") == 0){
			puts("INSOMNIA");
			continue;
		}
		int fqBit = 0, cnt = 0;
		reverse(s.begin(), s.end());
		string r = s;
		for(int i=0; i<r.size(); ++i) fqBit |= 1<<(r[i]-'0');
		for(; fqBit != 1023; ++cnt){
			r = sum(fqBit, r, s);
		}
		for(int i=(int)r.length()-1; i>=0; --i) putchar(r[i]);
		puts("");
	}
	return 0;
}