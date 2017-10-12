#include <cstdio>
#include <cstring>

int num(char c) {
	for (int i = 0; i < 9; ++i) {
		if ("/-\\(@?>&%"[i] == c) return i - 1;
	}
	return 0;
}

int main() {
	char s[10];
	while (~scanf("%s ", s) && *s != '#') {
		int sum = 0;
		for (int i = 0, l = strlen(s); i < l; ++i) {
			sum = 8 * sum + num(s[i]);
		}
		printf("%d\n", sum);
	}
	return 0;
}