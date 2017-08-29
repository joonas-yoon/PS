#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<vector<int>> f(6, vector<int>(2, 0));
	while (n--) {
		int s, y;
		scanf("%d %d", &s, &y);
		f[y - 1][s] += 1;
	}
	int rooms = 0;
	for (auto& g : f) {
		for (auto& x : g)
			rooms += (x + k - 1) / k;
	}
	printf("%d", rooms);
	return 0;
}