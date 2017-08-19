#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1,1,0,0 };
static int dx[] = { 0,0,-1,1 };

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	vector<ii> b(n);
	for (int x, i = 0; i < n; ++i) scanf("%d", &b[i].first), b[i].second = i;
	sort(b.begin(), b.end());
	vector<ii> rev(n);
	for (int i = 0; i < n; ++i) {
		rev[i].first = b[i].second;
		rev[i].second = a[n - 1 - i];
	}
	sort(rev.begin(), rev.end());
	for (auto& x : rev) {
		printf("%d ", x.second);
	}
	return 0;
}