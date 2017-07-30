#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<ii> LIS(vector<ii>& a) {
	int n = a.size();
	vector<ii> v(1, a[0]);
	vector<int> index(n, 0);
	for (int i = 1; i < n; ++i) {
		if (a[i].first > v.back().first) {
			index[i] = v.size();
			v.push_back(a[i]);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
			index[i] = it - v.begin();
		}
	}

	int len = v.size(), idx = len - 1;
	vector<ii> ret(len);
	for (int i = n - 1; i >= 0; --i) {
		if (index[i] == idx) {
			ret[idx--] = a[i];
		}
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<iii> a(n);
	vector<int> bak(n);
	for (int u, v, i = 0; i < n; ++i) {
		scanf("%d %d", &u, &v);
		a[i] = make_tuple( u, v, i );
		bak[i] = u;
	}

	sort(a.begin(), a.end());

	vector<ii> b(n);
	for (int i = 0; i < n; ++i) b[i] = { get<1>(a[i]), get<2>(a[i]) };

	auto lis = LIS(b);
	vector<bool> used(n, false);
	for (int i = 0; i < lis.size(); ++i) used[lis[i].second] = true;

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) ans.push_back(bak[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto& x : ans) printf("%d ", x);

	return 0;
}