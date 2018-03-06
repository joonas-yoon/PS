#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	fastio();
	string s, p, r;
	cin >> s >> p;
	reverse(all(s));
	reverse(all(p));
	int cr = 0, sl = s.length(), pl = p.length();
	for (int i = 0, j = 0; cr > 0 || i < sl || j < pl; ++i, ++j) {
		if (i < sl) cr += s[i] - '0';
		if (j < pl) cr += p[i] - '0';
		r += "0123456789"[cr % 10];
		cr /= 10;
	}
	reverse(all(r));
	cout << r;
	return 0;
}