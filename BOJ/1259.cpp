#include <cstdio>
#include <cstring>

int main() {
	char s[10];
	while (~scanf("%s ", s) && *s != '0') {
		bool palin = true;
		for (int l = 0, r = strlen(s) - 1; l < r; ++l, --r) {
			palin &= s[l] == s[r];
		}
		puts(palin ? "yes" : "no");
	}
	return 0;
}