#include <bits/stdc++.h>
using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	vector<int> v(m, 0);
	for (double x; ~scanf("%lf", &x);)
		v[(int)(x * m + 1e-12)]++;
    
	for (auto& x : v) printf("%d ", x);

	return 0;
}