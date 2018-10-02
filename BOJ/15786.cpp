#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	char p[1001];
	scanf("%d %d %s ", &n, &m, p);
	int plen = strlen(p);
	while (m--) {
		char s[1001];
		scanf("%s ", s);
		int slen = strlen(s);
		int idx = 0;

		for (int i = 0; idx < plen && i < slen; ++i) {
			if (s[i] == p[idx]) {
				idx++;
			}
		}

		puts(idx == plen ? "true" : "false");
	}
	return 0;
}