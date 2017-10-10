#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

// 주먹, 가위, 보의 번호
int name[3] = { 0,1,2 };
int beat[3] = { 1,2,0 };

int win(vector<ii>& a) {
	int aw = 0;
	for (auto& r : a) {
		aw += name[r.second - 1] == beat[name[r.first - 1]];
	}
	return aw;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<ii> log(n);
	for (auto& x : log) scanf("%d %d", &x.first, &x.second);
	int ans = 0;
	do {
		ans = max(ans, win(log));
	} while (next_permutation(name, name + 3));
	printf("%d\n", ans);
	return 0;
}