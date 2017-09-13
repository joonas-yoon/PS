#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[53];
	scanf("%s ", s);
	bool active[26] = {};
	int startAt[26] = {};
	int ans = 0;
	for (int i = 0; s[i]; ++i) {
		int id = s[i] - 'A';
		active[id] ^= 1;
		if (!active[id]) {
			for (int j = i + 1; s[j]; ++j) {
				int op = s[j] - 'A';
				ans += active[op] && startAt[op] > startAt[id];
			}
		}
		else {
			startAt[id] = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}