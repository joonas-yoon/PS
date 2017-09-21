#include <cstdio>

int main() {
	int n;
	char s[1001], p[1001];
	scanf("%d %s %s", &n, s, p);
	n %= 2;
	for (int i = 0; n && s[i]; ++i) s[i] = s[i] == '0' ? '1' : '0';
	for (int i = 0; p[i]; ++i) if (s[i] != p[i]) return puts("Deletion failed"), 0;
	puts("Deletion succeeded");
	return 0;
}