#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int n = 9;

int a[9][9];

bool correct(int y, int x) {
	bool fr[10] = {};
	for (int i = 0; i < n; ++i) {
		int k = a[y][i];
		if (k && fr[k]) return false;
		fr[k] = true;
	}
	memset(fr, false, sizeof(fr));
	for (int i = 0; i < n; ++i) {
		int k = a[i][x];
		if (k && fr[k]) return false;
		fr[k] = true;
	}
	memset(fr, false, sizeof(fr));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int k = a[y / 3 * 3 + i][x / 3 * 3 + j];
			if (k && fr[k]) return false;
			fr[k] = true;
		}
	}
	return true;
}

vector<ii> blank;
vector<int> cands[9][9];

void solve(int cur = 0) {
	if (cur >= blank.size()) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] == 0) return;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) printf("%d ", a[i][j]);
			puts("");
		}
		exit(0);
	}

	int cy = blank[cur].first, cx = blank[cur].second;
	for (auto& k : cands[cy][cx]) {
		a[cy][cx] = k;
		if (correct(cy, cx)) solve(cur + 1);
		a[cy][cx] = 0;
	}
}

int main() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
			if (0 == a[i][j]) blank.push_back({ i, j });
		}
	}

	for(auto& cur : blank){
		int cy = cur.first, cx = cur.second;
		for (int k = 1; k <= 9; ++k) {
			a[cy][cx] = k;
			if (correct(cy, cx)) cands[cy][cx].push_back(k);
			a[cy][cx] = 0;
		}
	}

	solve();
	return 0;
}