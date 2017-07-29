#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, q;
	scanf("%d %d %d", &n, &k, &q);
	
	int same = q;
	vector<int> firstUnread(n + 1, 0);
	vector<char> who(k + 1);
	for (int r, i = 1; i <= k; ++i) {
		char p;
		scanf("%d %c ", &r, &p);
		who[i] = p;
		if (!firstUnread[r]) firstUnread[r] = i;
		if (i == q) {
			if (r == 0) return puts("-1"), 0;
			same = firstUnread[r];
		}
	}

	vector<bool> read(n, false);
	for (int i = same; i <= k; ++i) read[who[i] - 'A'] = true;

	for (int i = 1; i < n; ++i) if (!read[i]) printf("%c ", 'A' + i);

	return 0;
}