#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	char s[1001], p[1001];
	scanf("%s %s", s, p);
	int minV = INF, pos = 0;
	for (int i = 0; i <= m - n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			cnt += s[j] != p[i+j];
		}

		if (cnt < minV) {
			minV = cnt;
			pos = i;
		}
	}

	printf("%d\n", minV);
	for (int i = 0, j = pos; i < n; ++i, ++j) {
		if (s[i] != p[j]) printf("%d ", i+1);
	}
	return 0;
}