#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	fastio();
    int T, a, b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout<< a+b << '\n';
    }
	return 0;
}