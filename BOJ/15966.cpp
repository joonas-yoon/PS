#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int ans = 0;

	vector<int> dp(1000001, 0); // [어떤 수]로 가능한 최대 길이
	for (int i = n - 1; i >= 0; --i) {
		int cur = a[i], next = cur + 1;
		if (dp[next] > 0) dp[cur] = dp[next] + 1;
		else dp[cur] = 1;
		ans = max(ans, dp[cur]);
	}

	printf("%d\n", ans);

	return 0;
}