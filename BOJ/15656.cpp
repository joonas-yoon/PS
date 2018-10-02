#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10];
int a[10];

void print(int cnt) {
	if (cnt >= m) {
		for (int i = 0; i < cnt; ++i) {
			printf("%d ", arr[i]);
		}
		puts("");
		return;
	}
	for (int i = 0; i < n; ++i) {
		arr[cnt] = a[i];
		print(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	print(0);
	return 0;
}