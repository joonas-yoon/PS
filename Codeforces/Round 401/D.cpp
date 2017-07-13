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
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

int main() {
	int n;
	scanf("%d", &n);
	vector<string> list(n);
	for (int i = 0; i < n; ++i) {
		char s[500001];
		scanf("%s ", s);
		list[i] = s;
	}

	for (int i = n-1; i > 0; --i) {
		int L1 = strlen(list[i - 1].c_str()), L2 = strlen(list[i].c_str());
		int idx = -1, len = min(L1, L2);

		int j = 0;
		while (j < len && list[i - 1][j] == list[i][j]) ++j;

		if (j == len) {
			idx = len;
		}
		else if (list[i - 1][j] > list[i][j]){
			idx = j;
		}

		// empty
		if (L2 == 1) idx = 1;

		// uncorrected order from idx
		if (idx != -1) {
			list[i - 1][idx] = 0;
		}
	}

	for (auto& s : list) {
		puts(s.c_str());
	}
	return 0;
}