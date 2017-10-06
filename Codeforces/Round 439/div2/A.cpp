#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> s;
	int n, a[2001], b[2001];
	scanf("%d", &n);
	set<int> q;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]), q.insert(a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]), q.insert(b[i]);

	int pairs = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = a[i] ^ b[j];
			pairs += q.find(x) != q.end();
		}
	}
	puts(pairs % 2 ? "Koyomi" : "Karen");

	return 0;
}