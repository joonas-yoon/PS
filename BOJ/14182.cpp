#include <cstdio>

int main(){
	int n;
	while (~scanf("%d", &n) && n) {
		if (n <= 1e6) printf("%d\n", n);
		else if (1e6 < n && n <= 5 * 1e6) printf("%d\n", n - n / 10);
		else printf("%d\n", n - n / 5);
	}
	return 0;
}