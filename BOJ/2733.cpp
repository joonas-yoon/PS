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

const int SIZE = 32768 + 1;

bool isCompileError(string& code, vector<int>& jump) {
	stack<int> bracket;
	for (int i = 0; i < code.length(); ++i) {
		if (code[i] == '[') bracket.push(i);
		if (code[i] == ']') {
			if (bracket.empty()) return true;
			int top = bracket.top();
			jump[top] = i;
			jump[i] = top;
			bracket.pop();
		}
	}
	return ! bracket.empty();
}

void run(string code) {
	int ptr = 0;
	vector<char> arr(SIZE + 1, 0);
	stack<int> index;
	
	int len = code.length();

	vector<int> jumpto(len + 1);
	for (int i = 0; i < len; ++i) jumpto[i] = i;

	if (isCompileError(code, jumpto)) {
		puts("COMPILE ERROR");
		return;
	}

	for (int i = 0; i < len; ++i) {
		if (code[i] == '>') ptr = (ptr + 1) % SIZE;
		if (code[i] == '<') ptr = (ptr - 1 + SIZE) % SIZE;
		if (code[i] == '+') arr[ptr] = (arr[ptr] + 1) % 256;
		if (code[i] == '-') arr[ptr] = (arr[ptr] - 1 + 256) % 256;
		if (code[i] == '.') putchar(arr[ptr]);
		if (code[i] == '[' && arr[ptr] == 0) i = jumpto[i];
		if (code[i] == ']' && arr[ptr] != 0) i = jumpto[i];
	}
	puts("");
}

int main() {
	int T, Tcase = 1;
	cin >> T;
	string s, code;
	while (getline(cin, s)) {
		if (s.compare("end") == 0) {
			printf("PROGRAM #%d:\n", Tcase++);
			run(code);
			code.clear();
			continue;
		}

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '%') break;
			if (s[i] != ' ') code.push_back(s[i]);
		}
	}
	return 0;
}