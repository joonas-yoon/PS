#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[x - 1] = i + 1;
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", i + 1 - a[i]);

	return 0;
}