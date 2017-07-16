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
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

char s[1000001], p[1000001];

int fq_s[26], fq_p[26];

int main() {
	scanf("%s %s", s, p);
	int sl = strlen(s), pl = strlen(p);

	for (int i = 0; s[i]; ++i) if (s[i] != '?') fq_s[s[i] - 'a']++;
	for (int i = 0; p[i]; ++i) fq_p[p[i] - 'a']++;

	for (int i = 0; i < sl; ++i) {
		if (s[i] != '?') putchar(s[i]);
		else {
			char ch = 'a';
			double minNeed = INF;
			for (int i = 0; i < 26; ++i) {
				if (fq_p[i] == 0) continue;

				double need = (double)fq_s[i] / (double)fq_p[i];
				if (need < 0) continue;

				if (minNeed > need) {
					minNeed = need;
					ch = 'a' + i;
				}
			}

			putchar(ch);
			fq_s[ch - 'a']++;
		}
	}

	return 0;
}