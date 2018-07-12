#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	fastio();

	int n;
	cin >> n;
	vector<char> v(n);
	FOR(i, n){
		string s;
		cin >> s;
		v[i] = s[0];
	}
	sort(all(v));

	int ans = 0;
	char c = 'A';
	FOR(i, n)
		if (v[i] == c)
			++ans, ++c;

	cout << ans <<'\n';

	return 0;
}