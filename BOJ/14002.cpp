#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	vector<int> lis(1, a[0]);
	vector<int> index(n);
	for (int i = 0; i < n; ++i) index[i] = i;
	for (int i = 1; i < n; ++i) {
		auto it = lower_bound(lis.begin(), lis.end(), a[i]);
		if (it == lis.end()) {
			index[i] = lis.size();
			lis.push_back(a[i]);
		}
		else {
			*it = a[i];
			index[i] = it - lis.begin();
		}
	}

	printf("%d\n", lis.size());
	int id = (int)lis.size() - 1;
	vector<int> ans(lis.size());
	for (int i = n - 1; i >= 0; --i) {
		if (index[i] == id) {
			ans[id--] = a[i];
		}
	}

	for (auto& x : ans) printf("%d ", x);

	return 0;
}