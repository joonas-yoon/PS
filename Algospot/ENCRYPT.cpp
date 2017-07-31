#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char s[101];
		scanf("%s ", s);
		int len = strlen(s);
		for (int i = 0; i < len; i += 2) putchar(s[i]);
		for (int i = 1; i < len; i += 2) putchar(s[i]);
		puts("");
	}
	return 0;
}