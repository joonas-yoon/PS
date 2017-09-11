#include <bits/stdc++.h>
using namespace std;

int a, b, c;
set<int> ans;
bool chk[201][201][201];

// x -> y
void move(int *x, int xvol, int *y, int yvol) {
	int tx = *x, ty = *y;
	*y = min(yvol, ty + tx);
	*x = max(0, tx - (yvol - ty));
}

void f(int x, int y, int z) {
	if (chk[x][y][z]) return;

	chk[x][y][z] = true;
	if(x == 0) ans.insert(z);

	int* p[3] = { &x, &y, &z };
	int* v[3] = { &a, &b, &c };
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) continue;
			int ta = *p[i], tb = *p[j];
			move(p[i], *v[i], p[j], *v[j]);
			f(x, y, z);
			*p[i] = ta, *p[j] = tb;
		}
	}
}

int main() {
	scanf("%d %d %d", &a, &b, &c);

	f(0, 0, c);
	for (auto& x : ans) printf("%d ", x);
	return 0;
}