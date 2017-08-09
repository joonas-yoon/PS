#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int h, u, d, f;
	while (~scanf("%d %d %d %d", &h, &u, &d, &f) && h && d) {
		double F = f / 100.;
		double cur = 0;
		int day = 1, n = 1;
		bool ok = true;
		for (;; ++n, ++day) {
			cur += u * max(0.0, (1.0 - (n - 1)*F));
			if (cur > h) break;
			cur -= d;
			if (cur < 0) {
				ok = false; break;
			}
		}
		printf("%s on day %d\n", ok ? "success" : "failure", day);
	}
	return 0;
}