#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

char chr(int x) {
	if (x > 9) return x - 10 + 'A';
	return x + '0';
}

int main() {
	char s[25];
	while (gets(s) && *s != '#') {
		int n, k;
		scanf(" %d %d ", &n, &k);
		string res;
		for (int i = k; i; i /= n) {
			res = string(1, chr(i % n)) + res;
		}
		printf("%s, %d, %s\n", s, k, res.c_str());
	}
	return 0;
}