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

int n;
vector<int> t;

void build(){
	for (int i = n - 1; i > 0; --i) {
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
}

void update(int k, int val) {
	for (t[k += n] = val; k > 1; k >>= 1) {
		t[k >> 1] = t[k] + t[k ^ 1];
	}
}

int query(int l, int r) { // [l, r)
	int sum = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main() {
	int q;
	scanf("%d %d", &n, &q);
	t.resize(2 * n);
	for (int i = 0; i < n; ++i) scanf("%d", &t[n + i]);
	build();
	while (q--) {
		int x, a, b, c, d;
		scanf("%d %d %d", &x, &a, &b);
		int sum = query(a - 1, b);
		if (x == 1) {
			printf("%d\n", sum);
			int oa = t[n + a - 1], ob = t[n + b - 1];
			update(a - 1, ob);
			update(b - 1, oa);
		}
		else {
			scanf("%d %d", &c, &d);
			printf("%d\n", sum - query(c - 1, d));
		}
	}
	return 0;
}