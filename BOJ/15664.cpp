#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, res[10];
int c[10010], cm[10010];
int a[10];

void print(int cur, int cnt) {
	if (cnt >= m) {
		for (int i = 0; i < cnt; ++i) {
			printf("%d ", res[i]);
		}
		puts("");
		return;
	}
	for (int i = cur; i < n; ++i) {
		if (i > cur && a[i] == a[i - 1]) continue;
		int x = a[i];
		if (c[x] < cm[x]) {
			c[x]++;
			res[cnt] = x;
			print(i + 1, cnt + 1);
			c[x]--;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		cm[a[i]]++;
	}
	sort(a, a + n);
	print(0, 0);
	return 0;
}