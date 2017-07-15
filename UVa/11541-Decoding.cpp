#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		char s[201];
		scanf("%s ", s);
		printf("Case %d: ", i);
		string p;
		for (int num = 0, dec = 1, j = strlen(s) - 1; j >= 0; --j) {
			if (s[j] >= '0' && s[j] <= '9') {
				num += dec * (s[j] - '0');
				dec *= 10;
			}
			else {
				for (int k = 0; k < num; ++k) p.push_back(s[j]);
				num = 0;
				dec = 1;
			}
		}
		for (int i = (int)p.length() - 1; i >= 0; --i) putchar(p[i]);
		puts("");
	}
	return 0;
}