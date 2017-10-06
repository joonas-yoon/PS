#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int n, len;
int ans[55], idx;
char s[101];

void solve(int k, lld state = 0) {
	if (k >= len){
		if (state == (1LL << n) - 1) {
			for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
			exit(0);
		}
		return;
	}
	int one = s[k] - '0' - 1;
	if (one >= 0 && !(state & (1LL << one))) {
		ans[idx++] = one;
		solve(k + 1, state | (1LL << one));
		idx--;
	}
	if (k + 1 < len) {
		int two = 10 * (one + 1) + (s[k + 1] - '0') - 1;
		if (two >= 0 && two < 50 && !(state & (1LL << two))) {
			ans[idx++] = two;
			solve(k + 2, state | (1LL << two));
			idx--;
		}
	}
}

int main() {
	scanf("%s ", s);
	len = strlen(s);
	if (len < 10) n = len;
	else n = (len - 9) / 2 + 9;
	solve(0);
	return 0;
}