#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int fq[10] = {};
	for (int i = 0; i < s.length(); ++i) {
		int x = s[i] - '0';
		if (x == 9) x = 6;
		fq[x]++;
	}

	fq[6] -= fq[6] / 2;

	int ans = 0;
	for (int i = 0; i < 9; ++i) ans = max(ans, fq[i]);
	printf("%d\n", ans);

	return 0;
}