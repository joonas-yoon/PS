#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long lld;

int main() {
	lld a, b, c, testCase = 1;
	while (~scanf("%lld %lld %lld", &a, &b, &c)) {
		if (a == 0 && b == 0 && c == 0) break;

		char ch = 'a';
		int s[] = { a,b,c };
		for (int i = 0; i < 3; ++i) if (s[i] < 0) ch = i + 'a';

		lld x = a*a + b*b;
		if (ch == 'a') x = c*c - b*b;
		else if( ch == 'b' ) x = c*c - a*a;

		printf("Triangle #%lld\n", testCase++);
		if (x <= 0) puts("Impossible.\n");
		else printf("%c = %.3lf\n\n", ch, sqrt(x));
	}
	return 0;
}