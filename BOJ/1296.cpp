#include <bits/stdc++.h>
using namespace std;

int percent(vector<int> fr, string s) {
	for (auto& c : s) fr[c - 'A']++;
	int L = fr['L' - 'A'], O = fr['O' - 'A'], V = fr['V' - 'A'], E = fr['E' - 'A'];
	int ans = ((L + O) * (L + V)) % 100;
	ans = (ans * (L + E) * (O + V)) % 100;
	ans = (ans * (O + E) * (V + E)) % 100;
	return ans;
}

int main() {
	char s[25], p[25];
	int n, m = 0;
	vector<int> f(26, 0);
	scanf("%s %d " , s, &n);
	for (int i = 0; s[i]; ++i) f[s[i] - 'A'] ++;
	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		scanf("%s ", p);
		ans.push_back(p);
	}
	sort(ans.begin(), ans.end(), [&](string s, string p) -> bool {
		int p1 = percent(f, s), p2 = percent(f, p);
		if (p1 == p2) return s < p;
		return p1 > p2;
	});
	puts(ans.front().c_str());
	return 0;
}