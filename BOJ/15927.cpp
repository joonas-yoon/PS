#include <bits/stdc++.h>
using namespace std;

bool isPalin(char *s) {
	int l = 0, r = strlen(s) - 1;
	while (l < r) {
		if (s[l++] != s[r--]) return false;
	}
	return true;
}

int main() {
	char s[500001];
	scanf("%s", s);
	int len = strlen(s);
	bool one = true;
	for(int i=1; i<len; ++i){
		one &= s[i - 1] == s[i];
	}
	if (one) return puts("-1"), 0;

	printf("%d\n", isPalin(s) ? len - 1 : len);
	
	return 0;
}