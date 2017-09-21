#include <cstdio>
#include <cstring>

bool surp(char *s) {
	int len = strlen(s);
	for (int k = 1; k < len - 1; ++k) {
		bool used[700] = {};
		for (int i = 0, j = k; j < len; ++i, ++j) {
			int x = 26 * (s[i] - 'A') + s[j] - 'A';
			if (used[x]) return false;
			used[x] = true;
		}
	}
	return true;
}

int main() {
	char s[100];
	while (~scanf("%s ", s) && *s != '*') {
		printf("%s is %ssurprising.\n", s, surp(s) ? "" : "NOT ");
	}
	return 0;
}