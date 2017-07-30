#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	vector<int> v(26, -1);
	cin >> s;
	for (int i = 0; i < s.length(); ++i) if(v[s[i] - 'a'] < 0) v[s[i] - 'a'] = i;
	for (auto& x : v) printf("%d ", x);
	return 0;
}