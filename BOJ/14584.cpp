#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

bool match(char *s, char *p, int k) {
	int sl = strlen(s), pl = strlen(p);
	if (pl > sl) return false;
	for (int i = 0; i < pl; ++i) {
		if ((s[i] - 'a' + k) % 26 != p[i] - 'a') return false;
	}
	return true;
}

int print(char *s, int k) {
	for (int i = 0; s[i]; ++i) {
		putchar((s[i] - 'a' + k) % 26 + 'a');
	}
	return 0;
}

int main() {
	char s[101];
	int n;
	scanf("%s %d", s, &n);
	char p[21][101];
	for (int i = 0; i < n; ++i) {
		scanf("%s ", p[i]);
	}

	int len = strlen(s);
	for (int x = 0; x < 26; ++x) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < n; ++j) {
				if (match(s + i, p[j], x)) {
					return print(s, x);
				}
			}
		}
	}

	return 0;
}