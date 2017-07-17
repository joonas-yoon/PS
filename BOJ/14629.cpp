#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long lld;

#define LINF 0x3f3f3f3f3f3f3f3f

bool visit[10];

lld x, ans = LINF;

void gen(int n, lld k) {
	if (n == 0) {
		if (abs(x - ans) > abs(x - k)) ans = k;
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			gen(n - 1, 10 * k + i);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%lld", &x);

    int len = 0;
	for (lld temp = x; temp > 0; temp /= 10) ++len;
    
	if (len > 10) return puts("9876543210"), 0;

	for (int i = 0; i < 10; ++i) {
		visit[i] = true;
		gen(len - 1, i);
		visit[i] = false;
	}

	printf("%lld", ans);

	return 0;
}