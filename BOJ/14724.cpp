#include <bits/stdc++.h>
using namespace std;

char s[9][15] = {
	"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"
};

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	vector<int> v(9);
	for (int i = 0; i < 9; ++i) {
		int m = 0;
		for (int x, j = 0; j < n; ++j) {
			scanf("%d", &x);
			m = max(x, m);
		}
		v[i] = m;
		ans = max(ans, m);
	}
	for (int i = 0; i < 9; ++i) {
		if (v[i] == ans) return puts(s[i]);
	}
	return 0;
}