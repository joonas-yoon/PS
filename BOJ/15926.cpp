#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	int n;
	char s[200001];
	scanf("%d %s ", &n, s);

	stack<int> st;
	vector<int> lastsize(n, 0);
	FOR(i, n) {
		if (s[i] == '(') {
			st.push(i);
			error = false;
		} else {
			if (st.empty()) {
				error = true;
			}
			else {
				int idx = st.top();
				st.pop();

				int cursize = i - idx + 1;
				if (idx > 0 && lastsize[idx - 1] > 0) {
					cursize += lastsize[idx - 1];
				}
				lastsize[i] = cursize;
			}
		}
	}
	
	int ans = 0;
	FOR(i, n) ans = max(ans, lastsize[i]);
	printf("%d\n", ans);

	return 0;
}