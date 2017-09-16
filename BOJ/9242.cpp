#include <bits/stdc++.h>
using namespace std;

char s[5][10][4] = {
	{ "***", "  *", "***", "***", "* *", "***", "***", "***", "***", "***" },
	{ "* *", "  *", "  *", "  *", "* *", "*  ", "*  ", "  *", "* *", "* *" },
	{ "* *", "  *", "***", "***", "***", "***", "***", "  *", "***", "***" },
	{ "* *", "  *", "*  ", "  *", "  *", "  *", "* *", "  *", "* *", "  *" },
	{ "***", "  *", "***", "***", "  *", "***", "***", "  *", "***", "***" }
};

char p[5][100001];

int number(int col) {
	for (int i = 0; i < 10; ++i) {
		bool find = true;
		for (int j = 0; j < 5; ++j)
			find &= strncmp(s[j][i], p[j] + col, 3) == 0;
		if (find) return i;
	}
	return -1;
}

int main() {
	for (int i = 0; i < 5; ++i) gets(p[i]);

	int sum = 0;
	for (int i = 0, len = strlen(p[0]); i < len; i += 4) {
		int k = number(i);
		if (k < 0) return puts("BOOM!!"), 0;
		sum = 10 * sum + k;
	}
	puts(sum % 6 == 0 ? "BEER!!" : "BOOM!!");
	return 0;
}