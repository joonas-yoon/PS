#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

// [i]번째 문자열의 자식(문자열, 그 번호)들
map<string, int> adj[20001];

void print(int cur, int dep) {
	for (auto next : adj[cur]) {
		for (int i = 0; i < dep; ++i) cout << ' ';
		cout << next.first << '\n';
		print(next.second, dep + 1);
	}
}

int main() {
	fastio();
	int n, id = 0;
	cin >> n;
	while (n--) {
		string s, word;
		cin >> s;
		int p = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '\\') {
				if (!adj[p].count(word)) adj[p][word] = ++id;
				p = adj[p][word];
				word = "";
			}
			else {
				word.push_back(s[i]);
			}
		}
		if (!word.empty()) {
			if (!adj[p].count(word)) adj[p][word] = ++id;
			p = adj[p][word];
		}
	}

	print(0, 0);

	return 0;
}