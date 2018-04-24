#include <cstdio>

int main() {
	int w, h, a;
	while (~scanf("%d %d %d", &w, &h, &a)){
		if (!w && !h && !a) break;
		w = w ? w : a / h;
		h = h ? h : a / w;
		a = a ? a : h * w;
		printf("%d %d %d\n", w, h, a);
	}
	return 0;
}