#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d ", &n);
	set<string> log;
	while (n--) {
		char name[1024], p[55];
		scanf("%s %s ", name, p);
		if (p[0] == 'e') log.insert(name);
		else log.erase(name);
	}
	stack<string> ans;
	for (auto& x : log) ans.push(x);
	while (!ans.empty()) {
		puts(ans.top().c_str());
		ans.pop();
	}
	return 0;
}