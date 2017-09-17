#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	bool con[6][6] = {};
	bool used[6] = {};
	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		con[a][b] = con[b][a] = true;
		used[a] = used[b] = true;
	}
	puts(con[1][3] && con[1][4] && con[3][4] && !used[2] && !used[5] ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
	return 0;
}