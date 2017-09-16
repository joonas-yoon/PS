#include <bits/stdc++.h>
using namespace std;

char morse[30][5] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
	".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
	".--", "-..-", "-.--", "--..", "..--", "---.", ".-.-", "----"
};

char chr(int idx) {
	if (idx >= 26) return "_.,?"[idx - 26];
	return idx + 'A';
}

int idx(int id) {
	if ('A' <= id && id <= 'Z') return id - 'A';
	for (int i = 0; i < 4; ++i) if ("_.,?"[i] == id) return 26 + i;
	return -1;
}

char f(string s) {
	for (int i = 0; i < 30; ++i)
		if (s.compare(morse[i]) == 0) return chr(i);
	return 0;
}

int main() {
	char s[1001];
	while (~scanf("%s ", s)) {
		int len = strlen(s);
		string str;
		vector<int> ls;
		for (int i = 0; i < len; ++i) {
			int id = idx(s[i]), pl = strlen(morse[id]);
			ls.push_back(pl);
			str += morse[id];
		}
		for(int i = 0, j = (int)ls.size() - 1; j >= 0 && i < str.length(); i += ls[j--])
			putchar(f(str.substr(i, ls[j])));
		puts("");
	}
	return 0;
}