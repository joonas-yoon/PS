#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for (auto& x : a) scanf("%d", &x);
	for (auto& x : b) scanf("%d", &x);

	int sum = 0;
	for (auto& x : a) sum += abs(x);
	for (auto& x : b) sum += abs(x);
	printf("%d", sum);
	return 0;
}