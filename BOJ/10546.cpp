#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

map<string, int> v;

int main() {
	fastio();
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		v[s] += 1;
	}
	for (int i = 1; i < n; ++i) {
		cin >> s;
		v[s] -= 1;
	}
	for (auto a : v) {
		if (a.second > 0) {
			cout << a.first << '\n';
			return 0;
		}
	}
	return 0;
}