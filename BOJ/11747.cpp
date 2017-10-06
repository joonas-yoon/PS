#include <bits/stdc++.h>
using namespace std;

bool have(vector<int>& a, int x) {
	int len = x == 0;
	for (int i = 1; i <= x; i *= 10) ++len;
	for (int i = 0; i + len - 1 < a.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < len; ++j) sum = 10 * sum + a[i + j];
		if (sum == x) return true;
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int x = 0; x < 100000; ++x) {
		if (!have(a, x)) return !printf("%d\n", x);
	}
	return 0;
}