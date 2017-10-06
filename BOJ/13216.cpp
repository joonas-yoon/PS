#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int Awin = 0, Bwin = 0;
	int as = 0, bs = 0;
	for (int i = 0; i <= s.length(); ++i) {
		if (i == s.length() || as > 20 || bs > 20) {
			Awin += as > bs;
			Bwin += as < bs;
			printf("%d-%d\n", as, bs);
			as = bs = 0;
		}
		if (s[i] == 'A') as += 1;
		else bs += 1;
	}
	puts(Awin > Bwin ? "A" : "B");
	return 0;
}