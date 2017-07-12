#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long lld;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> g(2, vector<int>(m, 0));
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			char s[101];
			scanf("%s ", s);
			for (int j = 0; j < m; ++j) g[k][j] |= 1 << (s[j] - 'A');
		}
	}

	int answer = 0;
	for (int i = 0; i < m; ++i) {
		answer += (g[0][i] & g[1][i]) == 0;
	}
	printf("%d", answer);

	return 0;
}