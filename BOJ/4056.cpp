#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int n = 9;

char a[9][10];

bool correct(int y, int x) {
	bool fr[10] = {};
	for (int i = 0; i < n; ++i) {
		int k = a[y][i] - '0';
		if (k && fr[k]) return false;
		fr[k] = true;
	}
	memset(fr, false, sizeof(fr));
	for (int i = 0; i < n; ++i) {
		int k = a[i][x] - '0';
		if (k && fr[k]) return false;
		fr[k] = true;
	}
	memset(fr, false, sizeof(fr));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int k = a[y / 3 * 3 + i][x / 3 * 3 + j] - '0';
			if (k && fr[k]) return false;
			fr[k] = true;
		}
	}
	return true;
}

vector<ii> blank;
vector<char> cands[9][9];

bool solve(int cur = 0) {
	if (cur >= blank.size()) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] == '0') return false;

		for (int i = 0; i < n; ++i) puts(a[i]);
		return true;
	}

	int cy = blank[cur].first, cx = blank[cur].second;
	for (auto& k : cands[cy][cx]) {
		a[cy][cx] = k;
		if (correct(cy, cx)) return solve(cur + 1);
		a[cy][cx] = '0';
	}
	return blank.empty();
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		memset(a, 0, sizeof(a));
		blank.clear();

		for (int i = 0; i < n; ++i) {
			scanf("%s", a[i]);
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == '0') blank.push_back({ i, j });
				cands[i][j].clear();
			}
		}

		for (auto& cur : blank) {
			int cy = cur.first, cx = cur.second;
			for (int k = 1; k <= 9; ++k) {
				a[cy][cx] = k + '0';
				if (correct(cy, cx)) cands[cy][cx].push_back(k + '0');
				a[cy][cx] = '0';
			}
		}

		if (!solve()) puts("Could not complete this grid.");
		puts("");
	}
	return 0;
}