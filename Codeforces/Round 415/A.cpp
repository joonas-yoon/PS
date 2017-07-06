#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>
#include <tuple>
using namespace std;

typedef long long lld;

#define INF 987654321

typedef pair<int, int> ii;

int roundUp(double n) {
	if (n - (int)n < .5) return n;
	return n + 1;
}

int main(){
	int n, k, sum = 0;
	scanf("%d %d", &n, &k);

	for(int i=0; i<n; ++i){
		int x;
		scanf("%d", &x);
		sum += x;
	}

	int x = 0;
	while (roundUp(sum / (n + x + .0)) < k) {
		sum += k;
		++x;
	}
	printf("%d", x);

	return 0;
}