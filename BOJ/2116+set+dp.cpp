#include <bits/stdc++.h>
using namespace std;

int n;
string dice[10001];
set<string> cases[10001]; // i번째를 돌렸을 때 가능한 모든 경우

string moveRight(string s) {
	string r(6, 0);
	static int p[] = { 1, 5, 2, 0, 4, 3 };
	for (int i = 0; i < 6; ++i) r[i] = s[p[i]];
	return r;
}

string moveDown(string s) {
	string r(6, 0);
	static int p[] = { 2, 1, 5, 3, 0, 4 };
	for (int i = 0; i < 6; ++i) r[i] = s[p[i]];
	return r;
}

void makeCases(int cur, string s) {
	if (cases[cur].find(s) != cases[cur].end()) return;
	cases[cur].insert(s);
	makeCases(cur, moveRight(s));
	makeCases(cur, moveDown(s));
}

int dp[10001][7];

int solve(int cur, char top) {
	if (cur >= n) return 0;

	int& ret = dp[cur][top-'0'];
	if (ret != -1) return ret;

	ret = 0;
	for (auto& next : cases[cur]) {
		if (next[5] == top) {
			int m = max({ next[1], next[2], next[3], next[4] }) - '0';
			ret = max(ret, m + solve(cur + 1, next[0]));
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		dice[i].resize(6);
		for (int x, j = 0; j < 6; ++j) {
			scanf("%d", &x);
			dice[i][j] = '0' + x;
		}
	}
	
	for (int i = 0; i < n; ++i) makeCases(i, dice[i]);

	int ans = 0;
	for (auto& s : cases[0]) {
		ans = max(ans, max({ s[1], s[2], s[3], s[4] }) - '0' + solve(1, s[0]));
	}
	printf("%d\n", ans);

	return 0;
}