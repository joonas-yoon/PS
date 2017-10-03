#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::ios::sync_with_stdio(false)

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int a[3][3];

int getA() {
	for (int i = 0; i < 3; ++i) {
		int sum = 0, find = 1;
		for (int j = 0; j < 3; ++j) {
			find &= a[i][j] > 0;
			sum += a[i][j];
		}
		if (find) return sum;
	}
	for (int i = 0; i < 3; ++i) {
		int sum = 0, find = 1;
		for (int j = 0; j < 3; ++j) {
			find &= a[j][i] > 0;
			sum += a[j][i];
		}
		if (find) return sum;
	}
	if (a[2][0] && a[1][1] && a[0][2]) return a[2][0] + a[1][1] + a[0][2];
	if (a[0][0] && a[1][1] && a[0][2]) return a[0][0] + a[1][1] + a[0][2];
	return -1;
}

bool inRange(int y, int x) {
	return 0 <= y && y < 3 && 0 <= x && x < 3;
}

bool isRight() {
	int ans = a[0][0] + a[1][0] + a[2][0];
	for (int i = 0; i < 3; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) sum += a[i][j];
		if (ans != sum) return false;
	}
	for (int i = 0; i < 3; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) sum += a[j][i];
		if (ans != sum) return false;
	}
	if (ans != a[2][0] + a[1][1] + a[0][2]) return false;
	if (ans != a[0][0] + a[1][1] + a[2][2]) return false;
	return true;
}

int main() {
	int fy = -1, fx;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) {
				fy = i, fx = j;
			}
		}
	}
	static int xd[] = { 0,1,1,1 };
	static int yd[] = { -1,-1,0,1 };

	for(int X=1; X<=20000; ++X){
		if (fy > 0) a[fy][fx] = X;

		int A = getA();
		int temp[3][3];
		memcpy(temp, a, sizeof(a));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (a[i][j] == 0) {
					for (int d = 0; d < 4; ++d) {
						int sum = 0, find = 0;
						for (int cy = i + yd[d], cx = j + xd[d]; inRange(cy, cx); cy += yd[d], cx += xd[d]) {
							find += a[cy][cx] > 0;
							sum += a[cy][cx];
						}
						for (int cy = i - yd[d], cx = j - xd[d]; inRange(cy, cx); cy -= yd[d], cx -= xd[d]) {
							find += a[cy][cx] > 0;
							sum += a[cy][cx];
						}
						if (find == 2) {
							a[i][j] = A - sum;
						}
					}
				}
			}
		}

		if (isRight()) {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) printf("%d ", a[i][j]);
				puts("");
			}
			return 0;
		}
		memcpy(a, temp, sizeof(a));
	}
    assert(false); // must be error
	return 0;
}