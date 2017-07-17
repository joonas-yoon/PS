#include <cstdio>

typedef long long lld;

int main() {
	int p, n;
	scanf("%d %d", &p, &n);
	int stone[101]={};
	for (int x, i = 0; i < n; ++i) {
		char dr[2];
		scanf("%d %s ", &x, dr);
		if (dr[0] == 'R') {
			for (int i = x + 1; i <= 100; ++i) stone[i] = (stone[i] + 1) % 3;
		}
		else {
			for (int i = x - 1; i >= 1; --i) stone[i] = (stone[i] + 1) % 3;
		}
	}

	int a = 0, b = 0, c = 0;
	int *x[3] = { &a, &b, &c };
	for (int i = 1; i <= 100; ++i) *(*(x + stone[i])) += 1;

	lld s = a + b + c;
	for (int i = 0; i < 3; ++i) {
		int k = *(*(x + i));
		printf("%.2lf\n", (lld)p * k / (s + 1e-12));
	}

	return 0;
}