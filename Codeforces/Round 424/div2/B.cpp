#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

int toLower(char ch) {
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
	return ch - 'a';
}

int main() {
	char a[27], b[27];
	char s[1001];
	scanf("%s %s %s", a, b, s);

	char m[53] = {};
	for (int i = 0; i < 26; ++i) {
		m[a[i] - 'a'] = b[i];
		m[a[i] - 'a' + 26] = b[i] - 'a' + 'A';
	}

	for (int i = 0; s[i]; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			putchar(s[i]);
		}
		else {
			putchar(m[toLower(s[i])]);
		}
	}
	
	return 0;
}