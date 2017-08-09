#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

int toInt(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
	return c - '0';
}

char toChr(int n) {
	if (n >= 10) return n - 10 + 'A';
	return '0' + n;
}

int main() {
	char s[8];
	int from, to;
	while (~scanf("%s %d %d ", s, &from, &to)) {
		lld num = 0, len = strlen(s);
		for (lld k = 1, i = len - 1; i >= 0; --i, k *= from) {
			num += toInt(s[i]) * k;
		}

		vector<int> ans;
		while (num > 0) {
			ans.push_back(num % to);
			num /= to;
		}
		if (ans.size() > 7) printf("%7s\n", "ERROR");
		else {
			for (int i = 0; i + ans.size() < 7; ++i) putchar(' ');
			for (int i = (int)ans.size() - 1; i >= 0; --i) putchar(toChr(ans[i]));
			puts("");
		}
	}

	return 0;
}