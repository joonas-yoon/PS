#include <cstdio>

int used[(1 << 25) / 32];

bool isUsed(int x) {
	int bit = x % 32;
	return (used[x / 32] & (1 << bit)) != 0;
}

void turnOn(int x) {
	used[x / 32] |= 1 << (x % 32);
}

int main() {
	int x;
	while (~scanf("%d", &x)) {
		if (!isUsed(x)) printf("%d ", x);
		turnOn(x);
	}
	return 0;
}