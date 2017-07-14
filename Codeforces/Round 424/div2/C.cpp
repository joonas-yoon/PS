#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

int main() {
	int n, k;
	scanf("%d %d", &k, &n);
	vector<int> sum(k);
	for (int x = 0, _x, i = 0; i < k; ++i) {
		scanf("%d", &_x);
		x += _x;
		sum[i] = x;
	}
	sort(sum.begin(), sum.end());
	sum.erase(unique(sum.begin(), sum.end()), sum.end());

	vector<int> b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	sort(b.begin(), b.end());

	int answer = 0;
	for(auto& a : sum){
		int availableNumber = b[0] - a;
		bool canBeMade = true;
		for (auto& bi : b) {
			canBeMade &= binary_search(sum.begin(), sum.end(), bi - availableNumber);
			if (!canBeMade) break;
		}
		answer += canBeMade;
	}
	printf("%d", answer);
	return 0;
}