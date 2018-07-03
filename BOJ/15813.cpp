#include <cstdio>

int main() {
	int n, ans = 0;
	scanf("%d ", &n);
	while(n--){
		char c;
		scanf(" %c", &c);
		ans += c - 'A' + 1;
	}
	printf("%d\n", ans);
	return 0;
}