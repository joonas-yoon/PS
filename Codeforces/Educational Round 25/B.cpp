#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

char s[11][11];

bool inRange(int y, int x) {
	return 0 <= y && y < 10 && 0 <= x && x < 10;
}

bool ans(int y, int x) {
	int dy[] = { -1,-1,0,1 };
	int dx[] = { 0,1,1,1 };
	char ch = 'X';
	for (int i = 0; i < 4; ++i) {
		int cnt = 0;
		for (int cy = y + dy[i], cx = x + dx[i]; inRange(cy, cx) && s[cy][cx] == ch; cy += dy[i], cx += dx[i]) ++cnt;
		for (int cy = y - dy[i], cx = x - dx[i]; inRange(cy, cx) && s[cy][cx] == ch; cy -= dy[i], cx -= dx[i]) ++cnt;
		if (cnt >= 4) return true;
	}
	return false;
}

bool solve() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (s[i][j] == '.' && ans(i, j)) return true;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 10; ++i) scanf("%s ", s[i]);

	puts(solve() ? "YES" : "NO");
	return 0;
}