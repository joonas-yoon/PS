#include <bits/stdc++.h>
using namespace std;

struct score {
	int s, t;
	bool operator < (const score& a) const {
        if (s == a.s) return t < a.t;
		return s < a.s;
	}
};

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int s, t;
		scanf("%d %d", &s, &t);
		set<score> dp;
		queue<score> q;
		q.push({ s, t });
		dp.insert({ s, t });
		int ans = 0;
		while (!q.empty()) {
			int qs = q.size();
			bool find = false;
			while (qs--) {
				score cur = q.front();
				q.pop();
                
				if (cur.s == cur.t) {
					// printf("%d %d\n", cur.s, cur.t);
					find = true;
					break;
				}
				score next[] = {
					{ cur.s + 1, cur.t },
					{ cur.s * 2, cur.t + 3 }
				};
				for (int i = 0; i < 2; ++i) {
					if (next[i].s <= next[i].t && dp.find(next[i]) == dp.end()) {
						dp.insert(next[i]);
						q.push(next[i]);
					}
				}
			}
			if (find) break;
			ans += 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}