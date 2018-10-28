#include <cstdio>
#include <cstring>

bool isPaline(char *s) {
	int l = 0, r = strlen(s) - 1;
	while (l <= r) {
		if (s[l++] != s[r--]) return false;
	}
	return true;
}

int main() {
	int k;
	char s[250001];
	scanf("%s %d", s, &k);
	puts(isPaline(s) ? "YES" : "NO");
	return 0;
}