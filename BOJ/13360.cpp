#include <cstdio>
#include <algorithm>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	char s[10001];
	gets(s);
	int rank = 25, star = 0;
	int need[27] = {};
	for (int giv = 5, i = 0; i < 27; ++i) {
		need[i] = giv;
		if (i >= 10 && i % 5 == 0) giv--;
	}

	bool rankOnce = false;
	bool legend = false;
	int winCount = 0;
	for (int i = 0; s[i]; ++i) {
		if (legend) break;

		if (s[i] == 'W') {
			star += 1;
			if (++winCount >= 3) {
				star += rank >= 6;
			}
		}
		else {
			star -= rank <= 20;
			if (rankOnce && rank >= 20) {
				rank = 20;
				star = max(0, star);
			}
			winCount = 0;
		}

		if (star < 0) {
			rank += 1;
			star = need[rank] - 1;
		}
		else if (star > need[rank]) {
			star -= need[rank];
			rank -= 1;
			rankOnce |= rank <= 20;
			legend |= rank < 1;
		}
	}

	if (legend) puts("Legend");
	else printf("%d\n", rank);

	return 0;
}