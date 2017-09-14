#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[51];
	scanf("%s ", s);
	string ans;
	for (int c = 0, i = (int)strlen(s) - 1; i >= 0; --i, ++c) {
		if (c && c % 3 == 0) ans = "," + ans;
		ans = string(1, s[i]) + ans;
	}
	puts(ans.c_str());
	return 0;
}