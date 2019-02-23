#include <string>
#include <vector>
#include <stack>
#include <functional>
using namespace std;

int solution(string str) {
	int ans = 0;
	stack<char> s;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') s.push('(');
		else {
			s.pop();
			if (str[i - 1] == ')') ans += 1;
			else ans += s.size();
		}
	}
	return ans;
}