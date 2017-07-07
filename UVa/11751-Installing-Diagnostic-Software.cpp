#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m;
	while (~scanf("%d %d", &n, &m) && n && m) {
		vector<bool> v(n, 0);
		vector<ii> wires(m);
		for (int x, y, i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			wires[i] = { min(x, y), max(x, y) };
		}
		sort(wires.rbegin(), wires.rend());
		for (auto& w : wires) {
			if (v[w.first] || v[w.second]) continue;
			v[min(w.first, w.second)] = true;
		}
		
		for (auto x : v) printf("%1d", (int)x);
		puts("");
	}
	return 0;
}