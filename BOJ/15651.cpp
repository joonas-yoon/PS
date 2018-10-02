#include <cstdio>

int n, m, arr[10];

void print(int cnt) {
	if (cnt >= m) {
		for (int i = 0; i < cnt; ++i) {
			printf("%d ", arr[i]);
		}
		puts("");
		return;
	}
	for (int i = 0; i < n; ++i) {
		arr[cnt] = i + 1;
		print(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	print(0);
	return 0;
}