#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

using lld = long long;

char a[20], b[20], c[20];
bool used[10];
int toi[26];

lld make_number(string s) {
	lld sum = 0;
	for(auto& ch : s)
		sum = 10LL * sum + toi[ch - 'A'];
	return sum;
}

void dfs(vector<char>& v, int cur) {
	if (cur >= v.size()) {
		lld an = make_number(a);
		lld bn = make_number(b);
		lld cn = make_number(c);
		if (an + bn == cn) {
			puts("YES");
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (!used[i]) {
			used[i] = true;
			toi[v[cur] - 'A'] = i;
			dfs(v, cur + 1);
			used[i] = false;
		}
	}
}

int main() {
	scanf("%s %s %s", a, b, c);
	int al = strlen(a), bl = strlen(b), cl = strlen(c);

	set<char> ch;
	for (int i = 0; i < al; ++i) ch.insert(a[i]);
	for (int i = 0; i < bl; ++i) ch.insert(b[i]);
	for (int i = 0; i < cl; ++i) ch.insert(c[i]);

	if (ch.size() > 10) return puts("NO"), 0;

	vector<char> v(all(ch));
	dfs(v, 0);
	puts("NO");

	return 0;
}