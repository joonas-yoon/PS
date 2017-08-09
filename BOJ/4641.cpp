#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[101];
	while (gets(s)) {
		if (!strcmp(s, "-1")) break;
		stringstream stream;
		stream.str(s);
		vector<int> a;
		int x, ans = 0;
		while (stream >> x) a.push_back(x);
		for (auto& v : a) {
			for (auto v2 : a) {
				if (v2 == a.back()) break;
				ans += (v2 == 2 * v);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}