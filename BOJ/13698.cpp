#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[201];
	int a[4] = { 1,2,3,4 };
	scanf("%s", s);
	int choose[6][2] = {
		{0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3}
	};
	for (int i = 0; s[i]; ++i) {
		int t = s[i] - 'A';
		swap(a[choose[t][0]], a[choose[t][1]]);
	}
	int mi, Mi;
	for (int i = 0; i < 4; ++i) {
		if (a[i] == 1) mi = i + 1;
		if (a[i] == 4) Mi = i + 1;
	}
	printf("%d\n%d\n", mi, Mi);
	return 0;
}