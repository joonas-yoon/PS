#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

bool solve(string str) {
	stack<string> stk;
	bool tag = false;
	string word;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '<') {
			tag = true;
			continue;
		}
		if (str[i] == '>') {
			tag = false;
			if (word.empty()) continue;
			bool halftag = false;
			for (int j = (int)word.length() - 1; j >= 0; --j) {
				if (word[j] != ' ') {
					if (word[j] == '/' && j != 0) {
						halftag = true;
						break;
					}
					break;
				}
			}
			if (halftag) {
				word = "";
				continue;
			}
			if (word[0] != '/') {
				stk.push(word);
				word = "";
				continue;
			}
			if (stk.empty()) return false;
			string top = stk.top();
			for (int j = 1; j < word.length(); ++j) {
				if (top[j - 1] == ' ') break;
				if (word[j] != top[j - 1]) return false;
			}
			stk.pop();
			word = "";
			continue;
		}
		if (tag) {
			word.push_back(str[i]);
		}
	}
	return stk.empty();
}

int main() {
	fastio();
	string str;
	while (getline(cin, str)) {
		if (!str.compare("#")) break;
		puts(solve(str) ? "legal" : "illegal");
	}
	return 0;
}