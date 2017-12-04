#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int a, b, i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
            adj[i].clear();
			for (int j = a - 1; j < b; ++j) {
				adj[i].push_back(j);
			}
		}

		int match = 0;
		fill(A, A + M, -1);
		fill(B, B + N, -1);
		for (int i = 0; i < M; i++) {
			if (A[i] == -1) {
				fill(visited, visited + M, false);
				if (dfs(i)) match++;
			}
		}
		printf("%d\n", match);
	}
	return 0;
}