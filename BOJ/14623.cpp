#include <cstdio>
#include <string>
using namespace std;

typedef long long lld;

lld binToInt(char *a) {
	lld r = 0;
	for (int i = 0; a[i]; ++i) {
		r = 2 * r + a[i] - '0';
	}
	return r;
}

int main() {
	char s[34], p[34];
	scanf("%s %s", s, p);
	lld x = binToInt(s) * binToInt(p);
	string ans;
	while (x > 0) {
		ans.push_back((x % 2) + '0');
		x /= 2;
	}
	bool leadingZero = true;
	for (int i = ans.length() - 1; i >= 0; --i) {
		leadingZero &= ans[i] == '0';
		if (!leadingZero) putchar(ans[i]);
	}
	return 0;
}