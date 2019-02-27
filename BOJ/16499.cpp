#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

int main() {
	int n;
	scanf("%d ", &n);
	set<string> m;
	while (n--) {
		char s[11];
		scanf("%s ", s);
		string str(s);
		std::sort(all(str));
		m.insert(str);
	}
	printf("%d\n", m.size());
	return 0;
}