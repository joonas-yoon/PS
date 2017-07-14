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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	if (n == 1) return puts("YES"), 0;

	int l = 0, r = n - 1;
	while (l + 1 < n && a[l] < a[l + 1]) l++;
	while (r - 1 >= 0 && a[r - 1] > a[r]) r--;

	bool ok = l <= r;
	if (!ok) return puts("YES"), 0;


	for (int i = l; i <= r; ++i) {
		ok &= a[i] == a[l];
	}

	puts(ok ? "YES" : "NO");
	
	return 0;
}