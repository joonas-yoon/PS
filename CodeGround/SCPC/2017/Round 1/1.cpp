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

int solve(char *s) {
	stack<char> p;
	int len = strlen(s), ans = 0;
	vector<int> res(len + 1, 0);
	int last_psize = 0;
	for (int i = 0; i < len; ++i) {
		if (strchr("({[", s[i])) p.push(s[i]);
		else {
			if (p.empty()) {
				// 잘못된 괄호열
				ans = max(ans, res[0]);
				res = vector<int>(len + 1, 0);
				last_psize = 0;
				continue;
			}
			char top = p.top();
			p.pop();
			int dep = p.size();
			if ((s[i] == ')' && top == '(') ||
				(s[i] == '}' && top == '{') ||
				(s[i] == ']' && top == '[')) {
				res[dep] += res[dep + 1] /* inner */ + 1 /* itself */;
				res[dep + 1] = 0;
				last_psize = dep;
			}
			else {
				// 잘못된 괄호열
				for (int i = 0; i <= last_psize; ++i)
					ans = max(ans, res[i]);
				res = vector<int>(len + 1, 0);
				p = stack<char>();
			}
		}
	}
	for(int i=0; i<=last_psize; ++i)
		ans = max(ans, res[i]);
	return 2 * ans;
}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);

	int T, test_case;
	scanf("%d ", &T);
	for (test_case = 1; test_case <= T; test_case++)
	{
		printf("Case #%d\n", test_case);

		char s[1000001];
		scanf("%s ", s);
		printf("%d\n", solve(s));
	}
	return 0;
}