#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int val(char c) {
	if (c == 'H') return 1;
	if (c == 'C') return 12;
	return 16;
}

bool isNumeric(char c) {
	return '0' <= c && c <= '9';
}

int solve(char *s) {
	stack<ii> st; /* val, level */
	for (int lv = 0, i = 0, len = strlen(s); i < len; ++i) {
		if (s[i] == '(') ++lv;
		else if (s[i] == ')') {
			int sum = 0;
			while (!st.empty() && st.top().second == lv) {
				sum += st.top().first;
				st.pop();
			}
			st.push({ sum, --lv });
		}
		else if (isNumeric(s[i])) {
            int x = st.top().first * (s[i] - '0');
            st.pop();
            st.push({ x, lv });
		}
		else {
			st.push({ val(s[i]), lv });
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top().first;
		st.pop();
	}
	return sum;
}

int main() {
	char s[101] = {};
    scanf("%s", s);
	printf("%d", solve(s));
	return 0;
}