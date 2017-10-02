#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int main(){
	int s, c;
	scanf("%d %d", &s, &c);

	vector<int> v(s);
	int l = 1, r = 1;
	for (auto& x : v) scanf("%d", &x), r = max(r, x);

	while (l <= r) {
		int mid = (l + r) / 2;
		int farCount = 0;
		for (auto& x : v) farCount += x / mid;
		
		if (farCount < c) r = mid - 1;
		else l = mid + 1;
	}

	lld sum = 0LL, far = r;
	lld farCount = 0;
	for (auto& f : v) {
		if(farCount + f / far >= c){
			if(c < farCount) sum += f;
			else sum += f - (c - farCount) * (lld)far;
		} else {
			sum += f - (f / far) * (lld)far;
		}
		farCount += f / far;
	}
	printf("%lld\n", sum);

	return 0;
}