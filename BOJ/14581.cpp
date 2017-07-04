#include <cstdio>

int main() {
	char s[25];
	scanf("%s", s);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			printf(":%s:", i%2 && j%2 ? s : "fan");
		puts("");
	}
	return 0;
}