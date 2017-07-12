#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long lld;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

#define MAX_N 1000001

char answer[2 * MAX_N];
vector<iii> ranges;
vector<string> str;

int main() {
	int T, len = 0, k;
	scanf("%d ", &T);
	while (T--) {
		char s[MAX_N];
		scanf("%s %d", s, &k);
		int pos, slen = strlen(s);
		while (k--) {
			scanf("%d", &pos); pos--;
			ranges.push_back(iii{ pos, pos + slen - 1, (int)str.size() });
			len = max(len, pos + slen);
		}
		str.push_back(s);
	}

	// sort by start point
	sort(ranges.begin(), ranges.end());

	int strIndex = 0;
	for (auto& r : ranges) {
		int s = get<0>(r), e = get<1>(r), idx = get<2>(r);
		while (strIndex < s) {
			answer[strIndex++] = 'a';
		}
		while (strIndex <= e) {
			answer[strIndex] = str[idx][strIndex - s];
			strIndex++;
		}
	}

	for (int i = 0; i < len; ++i) {
		putchar(answer[i]);
	}
	return 0;
}