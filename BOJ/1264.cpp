#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

char lower(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
	return c;
}

int main() {
	char s[256];
	while (gets(s) && *s != '#') {
		int ans = 0;
		for (int i = 0; s[i]; ++i) {
			ans += strchr("aeiou", lower(s[i])) != NULL;
		}
		printf("%d\n", ans);
	}
	return 0;
}	