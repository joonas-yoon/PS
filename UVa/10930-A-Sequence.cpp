#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, Tcase = 1;
	while (~scanf("%d", &n)) {
		vector<int> a(n), dp(1001, false);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		dp[0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 1000 - a[i]; j >= 0; --j) {
				if (j + a[i] >= 0) dp[j + a[i]] += dp[j];
			}
		}

		bool ok = 1 <= a[0];
		for (int i = 1; i < n; ++i) ok &= a[i - 1] < a[i];
		for (int i = 0; i < n; ++i) ok &= dp[a[i]] < 2;

		printf("Case #%d: ", Tcase++);
		for (int i = 0; i < n; ++i) printf("%d%s", a[i], i == n-1 ? "" : " ");
		printf("\nThis is %san A-sequence.\n", ok ? "" : "not ");
	}
	return 0;
}