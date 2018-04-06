#include <cstdio>

int main() {
	int cn, n = 1;
	scanf("%d", &cn);
	for (; cn != 1; n++) {
		if (cn % 2 == 0) cn /= 2;
		else cn = 3 * cn + 1;
	}
	printf("%d", n);
	return 0;
}