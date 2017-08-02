#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false);

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dp[101][11];

// 구간 [i, n) 에서 사용 가능한 숫자가 s개일 때, 나올 수 있는 양자화의 최소값
int quantize(const vector<int>& a, int i, int s) {
	int n = a.size();
	if (i == n) return 0;
	if (s <= 0) return INF;

	int& ret = dp[i][s];
	if (ret != -1) return ret;
	
	ret = INF;
	int sum = 0, squareSum = 0;
	for (int k = i; k < n; ++k) {
		int len = (k - i + 1);
		sum += a[k];
		squareSum += a[k] * a[k];
		// 구간의 평균을 양자화 할 숫자로 선택한다.
		int q = round((sum + 1e-12) / len);
		int diff = squareSum - 2 * q * sum + len * q * q;
		ret = min(ret, diff + quantize(a, k + 1, s - 1));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));
		int n, k;
		scanf("%d %d", &n, &k);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		printf("%d\n", quantize(a, 0, k));
	}
	return 0;
}