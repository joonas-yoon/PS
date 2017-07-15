#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> q;
	for (int x, i = 0; i < n*n; ++i) {
		scanf("%d", &x);
		q.push(-x);
		if (i >= n) q.pop();
	}
	printf("%d", -q.top());
	return 0;
}