#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<ii> inputs(n);
		set<int> xkind;
		for (auto& in : inputs) {
			scanf("%d %d", &in.first, &in.second);
			xkind.insert(in.first);
		}
		sort(inputs.begin(), inputs.end());
		vector<vector<ii>> cafe(xkind.size());
		for (int i = 0, idx = 0; i < inputs.size(); ++i){
			if ( i > 0 && inputs[i - 1].first != inputs[i].first) ++idx;
			cafe[idx].push_back(inputs[i]);
		}
		for (auto& c : cafe) {
			sort(c.begin(), c.end());
		}

		vector<ii> result;
		int lastY = cafe[0].front().second;
		if (cafe[0].size() > 1 && cafe[0][1].second < 0) {
			lastY = cafe[0].back().second;
		}
		for (auto& c : cafe) {
			int sz = c.size();
			bool rev = lastY == c[0].second;
			for (int i = 0; i < sz; ++i) {
				ii& tar = rev ? c[i] : c[sz - 1 - i];
				result.push_back(tar);
				lastY = tar.second;
			}
		}

		int m;
		scanf("%d", &m);
		while (m--) {
			int g;
			scanf("%d", &g);
			printf("%d %d\n", result[g - 1].first, result[g - 1].second);
		}
	}
	return 0;
}