#include <bits/stdc++.h>
using namespace std;

#define loop(i, k, n) for(int i = k; i < n; ++i)

int main() {
	char c[5]; int n[5], count[10] = {};
	loop(i, 0, 5) {
		scanf(" %c %d ", &c[i], &n[i]);
		count[n[i]] += 1;
	}

	// init
	int ans = 0, maxNumber = 0;
	bool continues = false, sameColor = true;
	loop(i, 0, 5) maxNumber = max(maxNumber, n[i]);
	loop(i, 1, 5) sameColor &= c[i] == c[i - 1];
	loop(i, 1, 6) {
		if (count[i] > 0) {
			bool find = true;
			loop(k, i, i + 5) find &= count[k] > 0;
			continues = find;
			break;
		}
	}

	// rule 1
	if (sameColor && continues) ans = max(ans, 900 + maxNumber);

	// rule 2
	int num = -1;
	loop(i, 1, 10) {
		if (count[i] == 4) {
			num = i;
			break;
		}
	}
	if (num != -1) ans = max(ans, 800 + num);

	// rule 3 & 6
	int s3 = -1, s2 = -1;
	loop(i, 1, 10) {
		if (count[i] == 3) s3 = i;
		if (count[i] == 2) s2 = i;
	}
	if (s3 != -1) {
		if (s2 != -1) ans = max(ans, 700 + 10 * s3 + s2);  // 3
		else ans = max(ans, 400 + s3); // 6
	}

	// rule 4
	if (sameColor) ans = max(ans, 600 + maxNumber);
	// rule 5
	if (continues) ans = max(ans, 500 + maxNumber);

	// rule 7 & 8
	int n20 = -1, n21 = -1;
	loop(i, 1, 10) {
		if (count[i] == 2) {
			if (n20 == -1) n20 = i;
			else n21 = i;
		}
	}
	if (n20 != -1) {
		if (n21 != -1) ans = max(ans, 300 + 10 * n21 + n20); // 7
		else ans = max(ans, 200 + n20); // 8
	}

	// rule 9
	ans = max(ans, 100 + maxNumber);

	printf("%d", ans);

	return 0;
}