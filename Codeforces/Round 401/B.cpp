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

int solve(string s, string m) {
	sort(s.begin(), s.end());
	sort(m.begin(), m.end());

	int n = s.size();
	int i = n - 1, j = n - 1; // s[i], m[j]
	int sf = 0;
	while (i >= 0) {
		if (s[i] >= m[j]) {
			i--;
			continue;
		}
		sf += s[i] < m[j];
		i--, j--;
	}

	string s2, m2;
	i = n - 1, j = n - 1;
	while (i >= 0) {
		if (s[i] > m[j]) {
			s2.push_back(s[i--]);
			continue;
		}
		i--, j--;
	}

	while (j >= 0) m2.push_back(m[j--]);

	sort(s2.begin(), s2.end());
	sort(m2.begin(), m2.end());
	int mf = 0;
	for (int i = 0; i < s2.size(); ++i) {
		mf += s2[i] > m2[i];
	}

	sort(s.begin(), s.end());
	sort(m.begin(), m.end());
	int mm = 0;
	for (int i = 0; i < n; ++i) {
		mm += s[i] > m[i];
	}

	printf("%d\n%d", min(mf, mm), sf);

	return 0;
}

int main() {
	int n;
	char s[2001] = {}, m[2001] = {};
	scanf("%d %s %s", &n, s, m);
	solve(s, m);
	return 0;
}