#include <cstdio>
#include <cstring>

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	char s[101];
	while(gets(s)){
		if (!strncmp(s, "***", 3)) break;
		for (int i = strlen(s) - 1; i >= 0; --i) putchar(s[i]);
		puts("");
	}
	return 0;
}