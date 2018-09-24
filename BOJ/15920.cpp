#include <cstdio>

int main() {
	int n, cur = 0;
	char s[11];
	scanf("%d %s", &n, s);

	bool r = false, drift = false;
	for (int i = 0; i < n && cur < 2; ++i) {
		if (s[i] == 'W') {
			for (int j = i - 1; j >= 0 && s[j] == 'P'; --j) {
				r = !r;
				drift |= cur == 1;
			}
			cur++;
		}
	}

	if (cur < 2) puts("0");
	else if (drift) puts("6");
	else puts(r ? "1" : "5");

	return 0;
}