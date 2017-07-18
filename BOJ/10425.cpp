#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long lld;

const lld MOD = 1e9 + 7;

map<lld, int> g;

int main() {
	int index = 0;
	lld a = 1, b = 1, c = 0;
	for(int i = 0; i < 100001; ++i){
		g[c] = index++;
		lld t = (a + b) % MOD;
		c = b;
		b = a;
		a = t;
	}

	int T;
	scanf("%d", &T);
	for (int x, i = 0; i < T; ++i) {
		char s[21001];
		scanf("%s ", s);
		lld n = 0;
		for (int i = 0; s[i]; ++i) {
			n = 10 * n + s[i] - '0';
			n %= MOD;
		}
		printf("%d\n", g[n]);
	}
	
	return 0;
}