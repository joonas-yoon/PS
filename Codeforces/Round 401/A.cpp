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
	int n, x;
	scanf("%d %d", &n, &x);
	int a[3] = {};
	a[x] = 1;
	n %= 6;
	int s = n % 2 == 0 ? 1 : 0;
	for (int i = 0; i < n; ++i) {
		swap(a[s], a[s + 1]);
		s ^= 1;
	}
	for (int i = 0; i < 3; ++i) if (a[i]) printf("%d", i);

	return 0;
}