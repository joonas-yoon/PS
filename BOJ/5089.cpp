#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	int n, tc = 0;
	while (~scanf("%d ", &n) && n) {
		set<string> m;
		char s[50];
		for (int i = 0; i < n; ++i) {
			gets(s);
			m.insert(s);
		}
		printf("Week %d %d\n", ++tc, m.size());
	}
	return 0;
}