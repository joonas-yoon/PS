#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int L, N;
	scanf("%d", &L);
	vector<int> a(L);
	for (auto& x : a) scanf("%d", &x);
	scanf("%d", &N);
	sort(a.begin(), a.end());
	int left = 0, right = a.back();
	for (auto& x : a) {
		if (x == N) return puts("0"), 0;
		if (x < N) left = x;
		if (x > N) {
			right = x;
			break;
		}
	}
	int l = max(0, N - (left + 1));
	int r = max(0, (right - 1) - N);
	printf("%d", l + (l*r) + r);

	return 0;
}