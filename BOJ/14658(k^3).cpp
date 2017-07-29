#include <bits/stdc++.h>
using namespace std;

int X[101], Y[101], L, K;

int countInBox(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < K; ++i) {
		if (!(x <= X[i] && X[i] <= x + L)) continue;
		if (!(y <= Y[i] && Y[i] <= y + L)) continue;
		cnt += 1;
	}
	return cnt;
}

int main() {
	int w, h;
	scanf("%d%d%d%d", &w, &h, &L, &K);
	for (int i = 0; i < K; ++i) scanf("%d %d", &X[i], &Y[i]);

	int ans = 0;
	// 트램펄린의 x축 선상에 있을 하나의 점과 y축 선상의 점을 고른다.
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			ans = max(ans, countInBox(X[i], Y[j]));
		}
	}
	printf("%d", K - ans);
	return 0;
}