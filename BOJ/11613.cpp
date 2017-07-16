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

char s[7][56] = {
	"xxxxx....xxxxxxxxxxxx...xxxxxxxxxxxxxxxxxxxxxxxxxx.....",
	"x...x....x....x....xx...xx....x........xx...xx...x..x..",
	"x...x....x....x....xx...xx....x........xx...xx...x..x..",
	"x...x....xxxxxxxxxxxxxxxxxxxxxxxxxx....xxxxxxxxxxxxxxxx",
	"x...x....xx........x....x....xx...x....xx...x....x..x..",
	"x...x....xx........x....x....xx...x....xx...x....x..x..",
	"xxxxx....xxxxxxxxxxx....xxxxxxxxxxx....xxxxxxxxxxx....."
};

int digit(char p[7][200], int col) {
	for (int x = 0; x <= 10; ++x) {
		bool it = true;
		for (int i = 0; i < 7; ++i) {
			for (int j = 0; j < 5; ++j) {
				it &= s[i][5 * x + j] == p[i][col + j];
				if (!it) break;
			}
			if (!it) break;
		}
		if (it) return x;
	}
	return 0;
}

int main() {
	char p[7][40 * 5] = {};
	for (int i = 0; i < 7; ++i) {
		scanf("%s ", p[i]);
	}

	int width = strlen(p[0]);
	lld sum = 0, num = 0;
	for (int c = 0; c < width; c += 6) {
		int n = digit(p, c);
		if (n == 10) { // +
			sum += num;
			num = 0;
		}
		else {
			num = 10 * num + n;
		}
	}
	sum += num;

	vector<int> nums;
	if (sum == 0) nums.push_back(0);
	else while (sum > 0) {
		nums.push_back(sum % 10);
		sum /= 10;
	}
	reverse(nums.begin(), nums.end());


	for (int i = 0, len = nums.size(); i < 7; ++i) {
		for (int c = 0; c < len; ++c) {
			for (int k = 0; k < 5; ++k) putchar(s[i][5 * nums[c] + k]);
			if (c != len - 1) putchar('.');
		}
		puts("");
	}

	return 0;
}