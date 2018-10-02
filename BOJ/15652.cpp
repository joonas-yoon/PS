#include <cstdio>

int n, m, arr[10];

void print(int cur, int cnt) {
	if (cnt >= m) {
		for (int i = 0; i < cnt; ++i) {
			printf("%d ", arr[i]);
		}
		puts("");
		return;
	}
	for (int i = cur; i < n; ++i) {
		arr[cnt] = i + 1;
		print(i, cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	print(0, 0);
	return 0;
}