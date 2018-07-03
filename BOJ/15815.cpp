#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '/') return a / b;
	return a * b;
}

int main() {
	char s[101];
	scanf("%s ", s);
	stack<int> a;
	for (int i = 0; s[i]; ++i) {
		if ('0' <= s[i] && s[i] <= '9')
			a.push(s[i] - '0');
		else {
			int a1 = a.top(); a.pop();
			int a2 = a.top(); a.pop();
			a.push(calc(a2, a1, s[i]));
		}
	}
	printf("%d\n", a.top());
	return 0;
}
