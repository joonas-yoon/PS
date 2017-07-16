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

int main() {
	int n;
	char s[101];
	scanf("%d %s ", &n, s);
	for (int i = 0; i < n; ++i) {
		int k = 0;
		while (i < n && s[i] == '1') {
			k += (s[i++] - '0');
		}
		printf("%d", k);
	}

	if (s[n - 1] == '0') printf("0");
	return 0;
}