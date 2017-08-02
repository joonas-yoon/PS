#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false);

string f(const string& s, int cur) {
	if (cur >= s.length()) return 0;
	if (s[cur] != 'x') return string(1, s[cur]);

	string r(1, 'x');
	vector<string> v(4);
	cur += 1;
	for (int i = 0; i < 4; ++i) {
		string& sub = v[(i + 2) % 4];
		sub = f(s, cur);
		cur += sub.length();
	}

	for (auto& sub : v) r += sub;
	return r;
}

int main() {
	fastio();
	int T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		cout << f(s, 0) << '\n';
	}
	return 0;
}