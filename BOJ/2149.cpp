#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

int main() {
	char key[11], cyph[101];
	scanf("%s %s", key, cyph);
	int len = strlen(key), clen = strlen(cyph), row = clen / len;

	vector<string> v(len);
	for (int i = 0; i < clen; ++i) {
		v[i / row].push_back(cyph[i]);
	}
	
	vector<ii> ord(len);
	for (int i = 0; i < len; ++i) ord[i] = { key[i] * len + i, i };
	sort(ord.begin(), ord.end());

	char ans[10][11] = {};
	for (int i = 0; i < len; ++i) {
		int col = ord[i].second;
		for (int j = 0; j < row; ++j) ans[col][j] = v[i][j];
	}

	for(int i=0; i<row; ++i)
		for(int j=0; j<len; ++j)
			putchar(ans[j][i]);

	return 0;
}
