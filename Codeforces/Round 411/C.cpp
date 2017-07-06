#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <set>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>1)

typedef pair<int, int> ii;

int main() {
	int n;
	scanf("%d", &n);
	if (n < 2) return puts("0"), 0;

	printf("%d", (n+1) / 2 - 1);

	return 0;
}