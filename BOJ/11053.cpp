#include <bits/stdc++.h>
using namespace std;

vector<int> dp, a;

int LIS(int k) {
	int n = a.size();
	if (k >= n) return 0;

	int& ret = dp[k];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = k + 1; i < n; ++i) {
		if(a[k] < a[i])
			ret = std::max(ret, 1 + LIS(i));
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	dp = vector<int>(n + 1, -1);
	a = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%d\n", LIS(0) - 1);
	return 0;
}