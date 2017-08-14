#include <cstdio>

const int INF = 0x3F3F3F3F;

int dp[1000001];
int trace[1000001];

int f(int n) {
	if (n <= 0) return INF;
	if (n == 1) return 0;

	int& ret = dp[n];
	if (ret) return ret;
	
	ret = INF;
	if (n % 3 == 0) {
		int next = 1 + f(n / 3);
		if (ret > next) {
			ret = next;
			trace[n] = n / 3;
		}
	}
	if (n % 2 == 0) {
		int next = 1 + f(n / 2);
		if (ret > next) {
			ret = next;
			trace[n] = n / 2;
		}
	}
	int next = 1 + f(n - 1);
	if (ret > next) {
		ret = next;
		trace[n] = n - 1;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	int cur = n;
	for (trace[0] = -1; trace[cur] != -1; cur = trace[cur])
		printf("%d ", cur);
	return 0;
}
