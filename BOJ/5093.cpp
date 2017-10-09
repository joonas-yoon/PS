#include <cstdio>

char toLower(char c) {
	if ('a' <= c) return c;
	return c - 'A' + 'a';
}

int main() {
	char s[15];
	while (~scanf("%s ", s) && *s != '#') {
		char rep[6] = {};
		int f[26] = {};
		for (int i = 0; s[i]; ++i) {
			if ((f[toLower(s[i]) - 'a'] += 1) >= 2) {
				int j = 0;
				for (; rep[j]; ++j) {
					if (rep[j] == toLower(s[i])) break;
				}
				rep[j] = toLower(s[i]);
				putchar("*?/+!"[j]);
			}
			else putchar(s[i]);
		}
		puts("");
	}
	return 0;
}