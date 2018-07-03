#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, a, b;
	string st;
	cin >> st >> T;
    while (T--) {
		cin >> a >> b;
		swap(st[a], st[b]);
	}
	cout << st <<'\n';
    return 0;
}