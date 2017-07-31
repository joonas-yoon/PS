#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false);

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

string p;

bool wild(const string& s, int i, int j) {
	int pl = p.length(), sl = s.length();
	if (i >= pl) return j >= sl;
	if (p[i] == s[j] || p[i] == '?') return wild(s, i + 1, j + 1);
	if (p[i] == '*') {
		for (int k = j; k <= sl; ++k) {
			if (wild(s, i + 1, k)) return true;
		}
	}
	return false;
}

int main() {
	fastio();
	int T, n;
	cin >> T;
	while (T--) {
		cin >> p >> n;
		vector<string> v;
		while (n--) {
			string s;
			cin >> s;
			if (wild(s, 0, 0)) v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (auto& s : v) cout << s <<'\n';
	}
	return 0;
}