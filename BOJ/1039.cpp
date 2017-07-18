#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int stringToInt(const string& s) {
	int r = 0;
	for (int i = 0; i < s.length(); ++i)
		r = 10 * r + s[i] - '0';
	return r;
}

int main() {
	int k;
	string s;
	cin >> s >> k;
	int m = s.length();
	if(m == 1) return puts("-1"), 0;

	queue<string> q;
	q.push(s);
	int dist = 0, ans = -INF;
	while (!q.empty() && dist <= k) {
		int qs = q.size();
		bool already[1000001] = {};
		while (qs--) {
			string cur = q.front();
			q.pop();

			int curInt = stringToInt(cur);
			// already[curInt] = true;
			if (dist == k) {
				ans = max(ans, curInt);
				continue;
			}

			for (int i = 0; i < m; ++i) {
				for (int j = i + 1; j < m; ++j) {
					if (i == 0 && cur[j] == '0') continue;
					swap(cur[i], cur[j]);
					int nextInt = stringToInt(cur);
					if (!already[nextInt]) {
						already[nextInt] = true;
						q.push(cur);
					}
					swap(cur[i], cur[j]);
				}
			}
		}
		dist++;
	}

	printf("%d", ans > -INF ? ans : -1);

	return 0;
}