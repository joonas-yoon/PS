#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	int cnt = 0;
	for (int bit = (1 << n) - 1; bit; --bit) {
		int sum = 0, idx = 0;
		for (int j = bit; j; j /= 2, idx++) {
			if (j % 2) sum += v[idx];
		}
		cnt += sum == s;
	}

	printf("%d\n", cnt);

	return 0;
}