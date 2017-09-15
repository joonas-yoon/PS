#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		if (!N) break;
		vector<pair<double, string>> v(N);
		double g = 0;
		for (auto& x : v) {
			cin >> x.second >> x.first;
			if (x.first > g) g = x.first;
		}
		for (auto& x : v) {
			if (g == x.first) cout << x.second << ' ';
		}
        puts("");
	}
	return 0;
}