#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int S;
int dp[2001][2001];

int f(int s, int c) {
	if (s == S) return 1;

	if (s <= 0 || s > 2000 || s < c) return INF;

	int& r = dp[s][c];
	if (r != -1) return r;

	r = INF;

	// copy
	if(s != c)
		r = min(r, 1 + f(s, s));

	// paste
	r = min(r, 1 + f(s + c, c));

	// erase
	r = min(r, 1 + f(s - 1, c));

	return r;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &S);
	printf("%d\n", f(1, 1));
	return 0;
}
