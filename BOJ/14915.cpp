#include <bits/stdc++.h>
using namespace std;

char ch[] = "0123456789ABCDEF";

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	if (m < 2) return printf("%d\n", m), 0;

	string r;
	while (m) {
		r = string(1, ch[m % n]) + r;
		m /= n;
	}
	puts(r.c_str());
	return 0;
}