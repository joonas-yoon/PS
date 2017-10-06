#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d ", &T);
	for(int tc=1; tc<=T; ++tc){
		char _s[1024];
		gets(_s);
		string s(_s), w;
		vector<string> ans;
		for (int i = 0; i <= s.length(); ++i) {
			if (i == s.length() || s[i] == ' ') {
				ans.push_back(w);
				w = "";
			}
			else w.push_back(s[i]);
		}
		printf("Case #%d:", tc);
		for (int i = (int)ans.size() - 1; i >= 0; --i) printf(" %s", ans[i].c_str());
		puts("");
	}
	return 0;
}