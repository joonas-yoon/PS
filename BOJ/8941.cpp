#include <cstdio>
#include <cstring>

int main() {
	double mol[] = { 12.01, 1.008, 16.00, 14.01 };
	int T, idx[26] = {};
	for (int i = 0; i < 4; ++i) idx["CHON"[i] - 'A'] = i;
	scanf("%d ", &T);
	while (T--) {
		char s[101];
		scanf("%s ", s);

		int cnt[4] = {};
		int len = strlen(s), i = 0;

		while (i < len) {
			int num = 0, x = s[i++] - 'A';
			while (i < len && s[i] >= '0' && s[i] <= '9') {
				num = 10 * num + s[i++] - '0';
			}
			cnt[idx[x]] += num ? num : 1;
		}

		double ans = 0.0;
		for (int i = 0; i < 4; ++i) ans += cnt[i] * mol[i];
		printf("%.3lf\n", ans);
	}
	return 0;
}