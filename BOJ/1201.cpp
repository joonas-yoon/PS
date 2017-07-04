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

vector<vector<int>> solve(int n, int m, int k) {
	// Imposibble
	vector<vector<int>> nil = vector<vector<int>>();
	if (n < m + k - 1 || n > m * k) return nil;

	// m개의 bucket
	vector<vector<int>> buc(m);

	// 하나는 k개만큼 꽉 채운다
	buc[0].resize(k);
	
	// 나머지 n-k개를 m-1개 그룹에 나눠담도록 크기를 나눈다.
	int numbers = n-k, groups = m - 1;
	for (int i = 0; i < m-1; ++i) {
		// 각자 담을 수 있는 크기 (최대한 공평하게)
		int groupSize = numbers / groups + (i < numbers % groups);
		buc[1+i].resize(groupSize);
	}

	// 1부터 N까지 하나씩 넣는다.
	int group = 0, count = 1;
	for (int i = 1; i <= n; ++i) {
		if (count > buc[group].size()) {
			group += 1;
			count = 1;
		}
		// 넣을 수 있는 그룹이 없다면 (모두 꽉 찼다면) 불가능한 조합
		if (group >= buc.size()) return nil;
		buc[group][count - 1] = i;
		count += 1;
	}

	for (int i = 0; i < m; ++i) reverse(buc[i].begin(), buc[i].end());
	return buc;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
    
	auto answer = solve(n, m, k);
	if (answer.empty()) return puts("-1"), 0;

	for (auto& group : answer) {
		for(auto& num : group) printf("%d ", num);
	}

	return 0;
}