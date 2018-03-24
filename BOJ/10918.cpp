#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#define gets(s) gets_s(s)
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

/*
IM CLUB DJ
IM GONNA MAKE
YOU MOVE
IM DJ KOO
IM GONNA MAKE
YOU DANCE
*/

string table[] = {
	"########.#######.###################.###",
	"..#..##..#######..###...##...##....#...#",
	"#...###.###...###.###.#.##.#.##.#.##.#.#",
	"#######..#..#..#..##....##...##...##...#",
	"########.#######.###########.###########",
	"######.#.########################.##.###",
	"###..#...#..#####################....###",
	"###.#######.############################",
	"###..#####..####...#..######..##########",
	"################.#.##.######.###########",
	"########.#########.##################.##",
	"..######.#....##...##.#.##...##.#.##...#",
	"#.######.####.##.###....###.###....##.##",
	"#....#...####..#.####.#.##...##.#.##...#",
	"######.#########.##########.############",
	"########################################",
	"#...##.#.##...##...##.#.##...##.#.##.#.#",
	"#...##.#.##.####.#.##.######.##.#.####.#",
	"#...##...##...##.#.##...##...##.#.##...#",
	"########################################",
	"########################################",
	"#...##...##.#.##...##.#.##.#.##...##.#.#",
	"#.#########.######.#########.###########",
	"#.#.##...##.#.##.#.##...##.#.##.#.##.#.#",
	"########################################"
};

string txt[] = {
	"a", "g", "m", "s", "b", "h", "n", "t",
	"c", "i", "o", "uv", "d", "j", "p", "w",
	"e", "kq", "z", "x", "f", "l", "r", "y",
	"0", "1", "2", "3", "3", "4", "4", "5",
	"5", "6", "6", "7", "7", "8", "9", "10"
};

char in[351][351];

bool match(int sy, int sx, int dy, int dx) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (in[sy + i][sx + j] != table[dy + i][dx + j])
				return false;
		}
	}
	return true;
}

string fez(int sy, int sx) {
	bool cleared = true;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			cleared &= in[sy + i][sx + j] != '#';
	}
	if (cleared) return "_";

	for (int kr = 0; kr < 5; ++kr) {
		for (int kc = 0; kc < 8; ++kc) {
			if (match(sy, sx, 5 * kr, 5 * kc))
				return txt[8 * kr + kc];
		}
	}
	return "";
}

int main() {
	int r, c;
	scanf("%d %d ", &r, &c);
	for (int i = 0; i < 6 * r - 1; ++i) scanf("%s ", &in[i]);
	for (int i = c - 1; i >= 0; --i) {
		for (int j = 0; j < r; ++j)
			cout << fez(6 * j, 6 * i);
		cout << "\n";
	}
	return 0;
}