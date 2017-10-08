#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,1,0,0 };
static int dy[] = { 0,0,-1,1 };

char a[30][30];

int ord(char c) {
	if ('a' <= c && c <= 'z') return c - 'a' + 26;
	return c - 'A';
}

int dist(char a, char b) { // a -> b
	int an = ord(a), bn = ord(b);
	if (an < bn) return (an - bn)*(an - bn);
	return 1;
}

int main() {
	int h, w, t, d;
	scanf("%d %d %d %d", &h, &w, &t, &d);
	for (int i = 0; i < h; ++i) scanf("%s ", a[i]);
	vector<vector<int>> D(h*w, vector<int>(h*w, INF));

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			D[i*w + j][i*w + j] = 0;
			for (int k = 0; k < 4; ++k) {
				int ny = i + dy[k], nx = j + dx[k];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w || abs(ord(a[i][j]) - ord(a[ny][nx])) > t) continue;
				D[i*w + j][ny*w + nx] = dist(a[i][j], a[ny][nx]);
			}
		}
	}

	for (int k = 0; k < h*w; ++k) {
		for (int i = 0; i < h*w; ++i) {	
			if (D[i][k] > d) continue;
			for (int j = 0; j < h*w; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	int ans = 0;
	for (int j = 0; j < h*w; ++j) {
		if (D[0][j] + D[j][0] <= d) {
			ans = max(ans, ord(a[j / w][j % w]));
		}
	}
	printf("%d\n", ans);

	return 0;
}