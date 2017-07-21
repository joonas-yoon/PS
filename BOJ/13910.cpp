#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> wok(m);
	for (int i = 0; i < m; ++i) scanf("%d", &wok[i]);
	sort(wok.begin(), wok.end());

	vector<int> wok2;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if(wok[i] + wok[j] <= n)
				wok2.push_back(wok[i] + wok[j]);
		}
	}
	sort(wok2.begin(), wok2.end());
	wok2.erase(unique(wok2.begin(), wok2.end()), wok2.end());

	vector<int> answer(n + 1, INF);
	answer[0] = 0;
	for(auto& doubleHand : wok2){
		for (int j = doubleHand; j <= n; ++j) {
			answer[j] = min(answer[j], 1 + answer[j - doubleHand]);
		}
	}

	for (auto& single : wok) {
		for (int j = single; j <= n; ++j) {
			answer[j] = min(answer[j], 1 + answer[j - single]);
		}
	}

	int ans = answer[n];
	printf("%d", ans < INF ? ans : -1);

	return 0;
}