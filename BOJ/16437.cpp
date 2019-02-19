#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;

const int MAX = 123456 + 10;

lld node[MAX];
vector<int> adj[MAX];

// cur번째 섬까지 도달할 수 있는 양의 수
lld solve(int cur) {
	lld sum = 0;
	for (int i = 0; i < adj[cur].size(); ++i) {
		sum += solve(adj[cur][i]);
	}
	return max(0LL, sum + node[cur]);
}

int main() {
	int n;
	scanf("%d ", &n);

	for (int pr, i = 1; i < n; ++i) {
		char ch;
		scanf("%c %d %d ", &ch, &node[i], &pr);
		if (ch == 'W') node[i] *= -1;
		adj[pr - 1].push_back(i);
	}

	printf("%lld\n", solve(0));

	return 0;
}
