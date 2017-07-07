#include <cstdio>

typedef long long lld;

int G[1000001];

int main() {
	int n;
	scanf("%d", &n);

	G[1] = 1;
	G[2] = 2;
	G[3] = 2;
	int len = 2, number = 3;
	for (int i = 4; i <= 1000001; ++i) {
		G[i] = number;
		len -= 1;
		if (len <= 0) {
			len = G[++number];
		}
	}

	int ans = 1;
	lld sum = 0;
	while((sum += G[ans++]) < n){
		// f(i)들의 합이 곧 수열의 길이.
	}
	printf("%d", ans-1);

	return 0;
}