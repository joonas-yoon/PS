#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

char toLower(char c) {
	if('A' <= c && c <= 'Z') return c - 'A' + 'a';
	return c;
}

bool compareLower(const string& s, const string& p) {
	string a = s, b = p;
	for (auto& x : a) x = toLower(x);
	for (auto& x : b) x = toLower(x);
	return a < b;
}

struct team {
	string name;
	int score;
	bool operator < (const team& t) const {
		if (score == t.score) return compareLower(name, t.name);
		return score > t.score;
	}
};

int main() {
	int tc = 0, n;
	while(~scanf("%d ", &n) && n){
		printf("Contest %d\n", ++tc);
		vector<int> p(n);
		for (int i = 0; i < n; ++i) scanf("%d ", &p[i]);
		int teams;
		scanf("%d ", &teams);
		vector<team> sc(teams);
		for (auto& t : sc) {
			char s[1024];
			gets(s);
			string w;
			vector<string> words;
			for (int i = 0, len = strlen(s); i <= len; ++i) {
				if (i == len || s[i] == ',') {
					words.push_back(w);
					w = "";
				}
				else w.push_back(s[i]);
			}
			t.name = words[0];
			t.score = 0;
			for (int i = 1; i < words.size(); ++i) {
				int num[2] = {};
				for (int j = 0, af = 0; j < words[i].size(); ++j) {
					if (words[i][j] == '/') af = 1;
					else if (af && words[i][j] == '-') break;
					else num[af] = num[af] * 10 + words[i][j] - '0';
				}
				if (num[0] && num[1]) {
					t.score += p[i - 1];
				}
			}
		}
		sort(sc.begin(), sc.end());
		for (int i = 0, r = 0; i < teams; ++i) {
			if (i > 0 && sc[i].score == sc[i - 1].score);
			else r = i;
			printf("%d %s %d\n", r + 1, sc[i].name.c_str(), sc[i].score);
		}
	}
	return 0;
}