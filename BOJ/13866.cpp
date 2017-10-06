#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[4];
	for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);
	sort(a, a + 4);
	printf("%d\n", abs(a[2] + a[1] - a[3] - a[0]));
	return 0;
}