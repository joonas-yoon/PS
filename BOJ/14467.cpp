#include <cstdio>
#include <cstring>

int main() {
	int n, pos[11];
	scanf("%d", &n);
	memset(pos, -1, sizeof(pos));
	int ans = 0;
	while (n--) {
		int cow, k;
		scanf("%d %d", &cow, &k);
		if (pos[cow] == -1) pos[cow] = k;
		else {
			ans += k != pos[cow];
			pos[cow] = k;
		}
	}
	printf("%d\n", ans);
	return 0;
}