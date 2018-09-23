#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
	set<int> cache;
	int x = n;

	while (x != 1) {
		int r = 0;
		while (x) {
			r += (x % 10) * (x % 10);
			x /= 10;
		}
		x = r;

		if (x == n || cache.find(x) != cache.end()) return false;
		cache.insert(x);
	}
	return true;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		puts(f(n) ? "HAPPY" : "UNHAPPY");
	}
	return 0;
}