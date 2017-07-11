#include <cstdio>

int main() {
	int n, answer = 0;
	scanf("%d", &n);
	// a+b+c=n
	// b+2 <= c
	// a,b,c != 0, a는 짝수
	for (int a = 2; a <= n - 2; a += 2) {
		// b <= c-2 = (n-a-b)-2
		for (int b = 1; 2 * b <= n - a - 2; ++b) {
			answer++;
		}
	}
	printf("%d", answer);
	return 0;
}