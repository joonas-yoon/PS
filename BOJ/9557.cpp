#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		char str[1101]={};
		scanf("%d ", &n); gets(str);
		vector<string> v;
		string s;
		vector<bool> arabic;
		for (int i = 0; str[i]; ++i) {
			if (str[i] == ' ') {
				v.push_back(s);
				arabic.push_back(s[0] == '#');
				s.clear();
			}
			else s += string(1, str[i]);
		}
		if (s.length()) {
			v.push_back(s);
			arabic.push_back(s[0] == '#');
		}

		reverse(v.begin(), v.end());
		reverse(arabic.begin(), arabic.end());

		int cur = 0;
		while (cur < n) {
			if (!arabic[cur]) { cur++; continue; }
			int start = cur;
			while (cur < n && arabic[cur]) ++cur;
			reverse(v.begin() + start, v.begin() + cur);
		}

		for (auto& x : v) printf("%s ", x.c_str());
		puts("");
	}
	return 0;
}