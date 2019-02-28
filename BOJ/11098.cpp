#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<pair<int, string>> v(n);
		for (int i = 0; i < n; ++i) {
			char s[21];
			scanf("%d %s ", &v[i].first, s);
			v[i].second = string(s);
		}
		sort(all(v));
		puts(v[n - 1].second.c_str());
	}

	return 0;
}