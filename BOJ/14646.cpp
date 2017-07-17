#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<bool> used(n+1, false);
	int ans = 0, sum = 0;
	for (int x, i = 0; i < 2 * n; ++i) {
		scanf("%d", &x);
		sum += used[x] == false;
		sum -= used[x] == true;
		used[x] = true;
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}