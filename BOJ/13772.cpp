#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int hole(char c) {
	if (strchr("ADOPQR", c)) return 1;
	return c == 'B' ? 2 : 0;
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		char s[255];
		gets(s);
		int ans = 0;
		for (int i = 0; s[i]; ++i) ans += hole(s[i]);
		printf("%d\n", ans);
	}
	return 0;
}