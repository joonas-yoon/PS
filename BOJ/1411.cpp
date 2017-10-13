#include <bits/stdc++.h>
using namespace std;

bool isSimilar(char *s, char *p) {
	int sl = strlen(s), pl = strlen(p);
	if (sl != pl) return false;
	char sto[26] = {}, used[26] = {};
	for (int i = 0; i < sl; ++i) {
		if (sto[s[i] - 'a'] == 0) {
			if (used[p[i] - 'a']) return false;
			sto[s[i] - 'a'] = p[i], used[p[i] - 'a'] = 1;
		}
		else if (sto[s[i] - 'a'] != p[i]) return false;
	}
	return true;
}

int main() {
	int n;
	char s[100][52] = {};
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) scanf("%s ", s[i]);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans += isSimilar(s[i], s[j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}