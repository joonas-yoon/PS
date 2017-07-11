#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>2)

typedef pair<int, int> ii;

// [left, right]
lld solve(vector<int>& a, int left, int right) {
	if (left == right) return a[left];

	int mid = (left + right) / 2;
	int l = mid, r = mid + 1;

	int height = min(a[l], a[r]);
	lld area = height * 2LL;
	while (left < l || r < right) {
		// 높이가 더 큰 쪽으로 진행한다
		if (left < l && (r == right || a[l-1] > a[r+1])) {
			height = min(height, a[--l]);
		}
		else {
			height = min(height, a[++r]);
		}
		area = max(area, (r - l + 1LL) * height);
	}

	return max(
		max(
			solve(a, left, mid),
			solve(a, mid + 1, right)
		),
		area
	);
}

int main() {
	int T, n;
    scanf("%d", &T);
  	while(T--){
	    scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		printf("%lld\n", solve(a, 0, n-1));
	}
	return 0;
}