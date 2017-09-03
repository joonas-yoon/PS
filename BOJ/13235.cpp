#include <cstdio>
#include <cstring>

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	char s[25];
	gets(s);
	for (int l = 0, r = strlen(s) - 1; l < r; ++l, --r) {
		if (s[l] != s[r]) return puts("false"), 0;
	}
	puts("true");
	return 0;
}