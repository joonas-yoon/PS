#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <climits>
using namespace std;

typedef long long lld;

#define INF 987654321
#define LINF (LLONG_MAX>>1)

typedef pair<int, int> ii;

int transaction(vector<int>& v) {
	int n = v.size(), ans = 0;
	for (int i = 0; i < n; ++i) {
		bool found = 0;
		while (i + 1 < n && v[i] > v[i + 1]) ++i;
		while (i + 1 < n && v[i] <= v[i + 1]) ++i, found |= v[i] < v[i+1];
		ans += found;
	}
	return ans * 2;
}

int main(int argc, char** argv){
	setbuf(stdout, NULL);

	int T;
	scanf("%d ", &T);
	for (int N, test_case = 1; test_case <= T; test_case++)
	{
		printf("Case #%d\n", test_case);
		scanf("%d", &N);
		vector<int> v(N);
		for (auto& x : v) scanf("%d", &x);
		printf("%d\n", transaction(v));
	}
	return 0;
}