#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d ", &n);
	map<string, int> x;
	while (n--) {
		char s[51];
		scanf("%s ", s);
		x[s] += 1;
	}
	auto it = x.rbegin();
	printf("%s %d\n", it->first.c_str(), it->second);
	return 0;
}