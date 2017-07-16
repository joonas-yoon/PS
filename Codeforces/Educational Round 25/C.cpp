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
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i) {
		while(2 * k < a[i]) {
			ans += 1;
			k *= 2;
		}
		k = max(k, a[i]);
	}
	printf("%d", ans);
	return 0;
}