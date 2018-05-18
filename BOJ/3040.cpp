#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[10];
	for (int i = 0; i < 9; ++i) scanf("%d", &a[i]);
	int b[9] = { 0,0,0,0,0,0,0,1,1 };
	do {
		int sum = 0;
		for (int i = 0; i < 9; ++i)
			if (!b[i]) sum += a[i];

		if (sum == 100) {
			for (int i = 0; i < 9; ++i)
				if (!b[i]) printf("%d\n", a[i]);
			break;
		}
	} while (next_permutation(b, b + 9));
	return 0;
}