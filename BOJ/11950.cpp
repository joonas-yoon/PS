#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int r, c;
	scanf("%d %d ", &r, &c);
	char s[51][51];
	for (int i = 0; i < r; ++i) scanf("%s ", s[i]);

	int ans = INF;
	for (int m1 = 1; m1 < r - 1; ++m1) {
		for (int m2 = m1 + 1; m2 < r; ++m2) {
			int wrong = 0;
			for (int i = 0; i < r; ++i) {
				char right = 'W';
				if (m1 <= i && i < m2) right = 'B';
				else if (m2 <= i) right = 'R';

				for (int j = 0; j < c; ++j)
					wrong += s[i][j] != right;
			}
			ans = min(ans, wrong);
		}
	}
	printf("%d\n", ans);
    return 0;
}
