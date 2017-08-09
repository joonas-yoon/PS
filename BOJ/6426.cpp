#include <bits/stdc++.h>
using namespace std;

int main() {
	int z, i, m, l, tcase = 1;
	while (~scanf("%d %d %d %d", &z, &i, &m, &l) && z && i) {
		map<int, int> len;
		int cur = l, idx = 0;
		while (len.find(cur) == len.end()) {
			len[cur] = ++idx;
			cur = ((z * cur) + i) % m;
		}
		printf("Case %d: %d\n", tcase++, idx - len[cur] + 1);
	}

	return 0;
}