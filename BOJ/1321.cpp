#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

#define INF 987654321

typedef pair<int, int> ii;

int n;
vector<lld> t;

void modify(int p, lld value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

lld query(int l, int r) {  // sum on interval [l, r)
	lld res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

int main(){
	scanf("%d", &n);
	t.assign(2*n, 0LL);

	for (int i = 0; i < n; ++i) {
		scanf("%lld ", &t[n + i]);
	}

	// make tree
	for (int i = n - 1; i > 0; --i) {
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			scanf("%d", &c);
			modify(b - 1, t[n + b - 1] + c);
		}
		else {
			int l = 0, r = n;
			while (l <= r) {
				int mid = (l + r) / 2;
				int sum = query(0, mid);
				if (sum < b) l = mid + 1;
				else r = mid - 1;
			}
			printf("%d\n", l);
		}
	}

	return 0;
}
