#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii node[10001];

// x축에서의 위치 = 중위순회한 순서
int idx = 0;
vector<int> pos[10001]; // 이 깊이에 있는 노드들의 위치

int inorder(int x, int dep = 1) {
	int d = dep;
	if (node[x].first != -1) d = max(d, inorder(node[x].first, dep + 1));
	pos[dep].push_back(++idx);
	if (node[x].second != -1) d = max(d, inorder(node[x].second, dep + 1));
	return d;
}

int main() {
	int n, root;
	scanf("%d", &n);
	vector<bool> hasParent(n + 1, false);
	for (int x, f, s, i = 0; i < n; ++i) {
		scanf("%d %d %d", &x, &f, &s);
		node[x] = make_pair( f, s );
		hasParent[max(0, f)] = hasParent[max(0, s)] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (!hasParent[i]) root = i;
	}
	int maxDepth = inorder(root);
	int maxWidth = 1, ansLevel = 1;
	for (int i = 1; i <= maxDepth; ++i) {
		int sz = pos[i].size();
		int width = sz != 0;
		if( sz > 0 ) width = pos[i][sz - 1] - pos[i][0] + 1;
		if (maxWidth < width) {
			maxWidth = width;
			ansLevel = i;
		}
	}
	printf("%d %d", ansLevel, maxWidth);
	return 0;
}