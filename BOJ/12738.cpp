#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>1)

int LIS(vector<int>& v) {
	vector<int> r(1, v[0]);
	for (int i = 1; i < v.size(); ++i) {
		int x = v[i];
		if (r.back() < x) r.push_back(x);
		else *lower_bound(r.begin(), r.end(), x) = x;
	}
	return r.size();
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (auto& x : a) scanf("%d", &x);
	printf("%d", LIS(a));
	return 0;
}