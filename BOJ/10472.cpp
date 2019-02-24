#include <bits/stdc++.h>
using namespace std;

// 012
// 345
// 678
// x번째 칸을 누르면 뒤집히는 칸들의 번호
vector<int> adj[9] = {
	{1, 3}, {0, 2, 4}, {1, 5},
	{0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8},
	{3, 7}, {4, 6, 8}, {5, 7}
};

// 특정 비트를 뒤집는다
int flip(int n, int k) {
	return n ^ (1 << k);
}

int solve(int bit) {
	queue<int> q;
	q.push(bit);
	bool visit[1 << 10] = {};
	visit[bit] = true;
	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();

			if (cur == 0) return dist;

			// 현재 상태에서 9칸을 전부 눌러본다
			for (int k = 0; k < 9; ++k) {
				int tmp = flip(cur, k);
				for (int i = 0; i < adj[k].size(); ++i) {
					tmp = flip(tmp, adj[k][i]);
				}
				if (!visit[tmp]) {
					visit[tmp] = true;
					q.push(tmp);
				}
			}
		}
		++dist;
	}
	return 0;
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		char s[3][4] = {};
		for (int i = 0; i < 3; ++i) scanf("%s ", s[i]);
		int bit = 0;
		for (int i = 0; i < 9; ++i)
			bit |= (s[i / 3][i % 3] == '*') << i;
		printf("%d\n", solve(bit));
	}

	return 0;
}