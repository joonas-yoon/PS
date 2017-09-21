#include <cstdio>

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		int s[55] = {};
		for (int i = 1; i <= 16; ++i) scanf("%1d ", &s[i]);
		int sum = 0;
		for (int i = 16; i >= 1; --i) {
			if (i % 2) {
				s[i] *= 2;
				if (s[i] >= 10) s[i] = (s[i] / 10) + s[i] % 10;
			}
			sum += s[i];
		}
		puts(sum % 10 == 0 ? "T" : "F");
	}
	return 0;
}