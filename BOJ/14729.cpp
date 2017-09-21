#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<double> sevens;
	while (n--) {
		double xx;
		scanf("%lf ", &xx);
		sevens.push(xx);
		while (sevens.size() > 7) sevens.pop();
	}

	vector<double> ans;
	while (!sevens.empty()) {
		ans.push_back(sevens.top());
		sevens.pop();
	}
	for (int i = (int)ans.size() - 1; i >= 0; --i) {
		printf("%.3lf\n", ans[i]);
	}
	return 0;
}