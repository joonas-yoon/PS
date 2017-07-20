#include <cstdio>

bool song[1001000];

int main() {
	int n, l, d;
	scanf("%d %d %d", &n, &l, &d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			int t = (l + 5)*i + j;
			if(t <= 1001000) song[t] = true;
		}
	}

	for (int i = 0; i < 1001000; i += d) {
		if (!song[i]) return ~printf("%d", i);
	}
	return 0;
}