#include <bits/stdc++.h>
using namespace std;

bool diffOne(int a, int b) {
	int cnt = 0;
	while (a > 0) {
		cnt += a % 10 != b % 10;
		a /= 10;
		b /= 10;
	}
	return cnt == 1;
}

int main() {
	bool era[10001] = {};
	vector<int> primes;
	era[0] = era[1] = true;
	for (int i = 2; i < 10000; ++i) {
		if (era[i]) continue;
		for (int j = i*i; j < 10000; j += i) era[j] = true;
		if (1000 < i && i < 9999) {
			primes.push_back(i);
		}
	}

	vector<int> adj[10001];
	for (auto& p : primes) {
		for (auto& k : primes) {
			if( diffOne(p, k) ) adj[p].push_back(k);
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int start, end;
		scanf("%d %d", &start, &end);

		queue<int> q;
		q.push(start);
		vector<bool> visit(10001, false);
		int dist = 0;
		bool find = false;
		while (!q.empty()) {
			int qs = q.size();
			while (qs--) {
				int cur = q.front();
				q.pop();

				if (cur == end) {
					find = true;
					break;
				}

				for(auto& next : adj[cur]){
					if (!visit[next]) {
						q.push(next);
						visit[next] = true;
					}
				}
			}
			if (find) break;
			++dist;
		}

		if(!find) puts("Impossible");
		else printf("%d\n", dist);
	}

	return 0;
}