#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 9;
const double EPS = 1e-12;

static int dx[] = {0, 0, -1, 0};
static int dy[] = {-1, 1, 0, 0};

bool solve(string& s) {
	int n = s.length();

	int idx = 0;
	char sub[1000001] = {};

	for (int i = 0; i < n; ++i) {
		sub[idx++] = s[i];
		while (idx >= 4) {
			bool flag = true;
			idx -= 4;
			for (int j = 0; j < 4; ++j){
				if (sub[idx + j] != "PPAP"[j]) {
					flag = false;
					break;
				}
			}
			
			if (!flag) {
				idx += 4;
				break;
			}
			
			sub[idx++] = 'P';
		}
	}

	return idx == 1 && sub[0] == 'P';
}

int main() {
	string s;
	cin >> s;
	puts(solve(s) ? "PPAP" : "NP");
	return 0;
}