#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
	return !!strchr("aeiou", c);
}

bool solve(char *s) {
	bool ans = true;
	int len = strlen(s);
	vector<bool> isv(len);
	bool flag = false;
	for (int i = 0; i < len; ++i) {
		isv[i] = isVowel(s[i]);
		flag |= isv[i];
	}
	if (!flag) return false;

	for (int i = 1; i < len; ++i) {
		if (i > 1 && isv[i - 2] == isv[i - 1] && isv[i - 1] == isv[i]) return false;
		if (s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'o')) return false;
	}
	return true;
}

int main() {
	char s[25];
	while (~scanf("%s ", s)) {
		if (!strcmp(s, "end")) break;
		printf("<%s> is%s acceptable.\n", s, solve(s) ? "" : " not");
	}
	return 0;
}