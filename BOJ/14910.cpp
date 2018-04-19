#include <cstdio>
#include <vector>

bool solve(std::vector<int>& a) {
	for (int i = 0; i + 1 < a.size(); ++i)
		if (a[i] > a[i + 1]) return false;
	return true;
}

int main() {
	std::vector<int> a;
	for (int x; ~scanf("%d", &x);) a.push_back(x);
	puts(solve(a) ? "Good" : "Bad");
	return 0;
}