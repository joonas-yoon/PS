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

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d ", &v[i][j]);
	vector<int> len(n, 0);
	len[0] = 1;
	for (int i = 0; i < m; ++i) {
		int l = 1;
		for (int j = 1; j < n; ++j) {
			if (v[j - 1][i] > v[j][i]) l = 1;
			else l++;
			len[j] = max(len[j], l);
		}
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d %d", &l, &r); --l, --r;
		puts(len[r] >= r - l + 1 ? "Yes" : "No");
	}
	return 0;
}