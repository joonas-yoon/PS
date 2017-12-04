#include <bits/stdc++.h>
using namespace std;

// N: A 그룹 크기, M: B 그룹 크기
// A[i], B[i]: 각 정점이 매칭된 반대편 정점 번호
int N, M, A[5001], B[101];
// adj[i]: A[i]와 인접한 그룹 B의 정점들
vector<int> adj[5001];
bool visited[5001];

// A그룹에 속한 정점 a를 이분 매칭시켜서 성공하면 true
bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		// 반대편이 매칭되지 않았거나
		// 매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	// 매칭 실패
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int a, b, i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		adj[b - 1].push_back(a - 1);
	}

	int match = 0;
	// 초기값: -1
	fill(A, A + M, -1); // 노트북
	fill(B, B + N, -1); // 구매자
	for (int i = 0; i < M; i++) {
		// 아직 매칭되지 않은 그룹 A 정점에 대해 매칭 시도
		if (A[i] == -1) {
			// visited 배열 초기화
			fill(visited, visited + M, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	return 0;
}