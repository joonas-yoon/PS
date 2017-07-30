#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

char s[1000001];

int main() {
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	vector<int> start(26, -1), end(26, -1);
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'A';
		if (start[c] < 0) start[c] = i;
		end[c] = i;
	}

	vector<ii> v;
	for (int i = 0; i < 26; ++i) {
		if (end[i] != -1) {
			v.push_back({ start[i], /* close */ false });
			v.push_back({ end[i], true });
		}
	}
	sort(v.begin(), v.end());

	int stk = 0;
	for (auto& x : v) {
		if (x.second) --stk;
		else ++stk;
		if (stk > k) return puts("YES"), 0;
	}
	puts("NO");

	return 0;
}