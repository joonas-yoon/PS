#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long lld;

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int denies = 0, b2 = 0;
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (x == 1) {
			if (a > 0) a--;
			else if (b > 0) b--, b2++;
			else if (b2 > 0) b2--;
			else denies++;
		}
		else {
			if (b > 0) b--;
			else denies += 2;
		}
	}
	printf("%d\n", denies);
	return 0;
}