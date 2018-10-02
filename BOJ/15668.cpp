#include <bits/stdc++.h>
using namespace std;

bool isOk(int a, int b) {
	bool v[10] = {};
	for (int i = a; i > 0; i /= 10) {
		if (v[i % 10]) return false;
		v[i % 10] = true;
	}
	for (int i = b; i > 0; i /= 10) {
		if (v[i % 10]) return false;
		v[i % 10] = true;
	}
	return true;
}

// k자리 수를 만든다.
bool visit[10];

int n;

void make(int x) {
	if (x >= n || x > 98765) {
		return;
	}

	if (x > 0 && isOk(x, n - x)) {
		printf("%d + %d\n", x, n - x);
		exit(0);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			make(10 * x + i);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);

	make(0);

	puts("-1");
	return 0;
}