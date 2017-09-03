#include <bits/stdc++.h>
using namespace std;

int countBit(int n) {
	int s = 0;
	for (; n > 0; n /= 2) s += n & 1 != 0;
	return s;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, x, y;
		scanf("%d ", &n);
		vector<int> v(1001, 0);
		while (n--) {
			char a;
			scanf("%c %d %d ", &a, &x, &y);
			for (int i = x; i < y; ++i)
				v[i] ^= 1 << (a - 'A');
		}
		bool start = false;
		for (auto& a : v) {
			int k = countBit(a);
			if (k > 0) printf("%c", k - 1 + 'A');
		}
		puts("");
	}

	return 0;
}