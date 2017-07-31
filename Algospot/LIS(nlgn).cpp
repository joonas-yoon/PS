#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a) {
	vector<int> v(1, a[0]);
	for (int i = 1; i < a.size(); ++i) {
		if (v.back() < a[i])
			v.push_back(a[i]);
		else
			*lower_bound(v.begin(), v.end(), a[i]) = a[i];
	}
	return v.size();
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		printf("%d\n", LIS(a));
	}
	return 0;
}