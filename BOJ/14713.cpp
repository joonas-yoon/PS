#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> owner; // 이 단어는 몇 번째 앵무새가 말했다.
map<string, int> order; // 이 단어는 몇 번째로 말했다.

int main() {
	int n = 0;
	getline(cin, s);
	for (int i = 0; i < s.length(); ++i) n = 10 * n + s[i] - '0';
	vector<vector<string>> words(n, vector<string>());
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		string w;
		for (int j = 0, len = s.length(); j <= len; ++j) {
			if (j == len || s[j] == ' ') {
				owner[w] = i;
				order[w] = words[i].size();
				words[i].push_back(w);
				w = "";
			}
			else w.push_back(s[j]);
		}
	}
	getline(cin, s);
	vector<int> haveToSaid(n, 0); // i번째 앵무새가 말해야 할 단어 번호
	vector<int> lastSaid(n, 0); // 현재까지 말한 단어 번호
	string w;
	for (int i = 0, len = s.length(); i <= len; ++i) {
		if (i == len || s[i] == ' ') {
			if (owner.find(w) == owner.end()) {
				return puts("Impossible"), 0;
			}

			int id = owner[w];
			if(haveToSaid[id] != order[w]) {
				return puts("Impossible"), 0;
			}
			haveToSaid[id] += 1;
			w = "";
		}
		else w.push_back(s[i]);
	}

	// 모든 단어를 전부 말해야 한다.
	bool ans = true;
	for(int i=0; i<n; ++i){
		ans &= haveToSaid[i] == words[i].size();
	}
	puts(ans ? "Possible" : "Impossible");
	return 0;
}