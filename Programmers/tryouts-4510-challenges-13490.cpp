/*
 * https://programmers.co.kr/tryouts/4510/challenges/13490
 *
 * 정확성: 69.9
 * 효율성: 0.0
 * 합계: 69.9 / 100.0
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> dp[1001];

int solve(vector<int>& v, int cur, int n) {
	if (n <= 0 || cur >= v.size()) {
		int r = 0;
		for (int i = cur; i<v.size(); ++i)
			r += v[i] * v[i];
		return r;
	}

	if (dp[cur].find(n) != dp[cur].end())
		return dp[cur][n];

	int& ret = dp[cur][n];
	ret = 987654321;

	for (int i = 0; i <= min(n, v[cur]); ++i) {
		int x = v[cur] - i;
		ret = min(ret, x*x + solve(v, cur + 1, n - i));
	}
	return ret;
}

int solution(int n, vector<int> works){
    return solve(works, 0, n);
}