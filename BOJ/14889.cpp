#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

const int INF = 0x3F3F3F3F;

int table[20][20];

int team_power(vector<int>& team) {
	int n = team.size(), sum = 0;
	FOR(i, n) {
		REP(j, i + 1, n - 1) {
			int a = team[i], b = team[j];
			sum += table[a][b] + table[b][a];
		}
	}
	return sum;
}

int main() {
	fastio();

	int n;
	cin >> n;
	FOR(i, n) {
		FOR(j, n)
			cin >> table[i][j];
	}

	vector<int> team(n, 1);
	FOR(i, n / 2) team[i] = 0;

	int ans = INF;
	do {
		vector<int> S(n / 2), L(n / 2);
		for (int i = 0, si = 0, li = 0; i < n; ++i) {
			if (team[i]) L[li++] = i;
			else S[si++] = i;
		}

		ans = min(ans, abs(team_power(S) - team_power(L)));
	} while (next_permutation(all(team)));

	cout << ans << '\n';

	return 0;
}