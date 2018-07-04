#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)

char p[100001];
char s[400001];
int  a[100001];

int main() {
	fastio();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> p >> n >> s;
		int l = 0, r = -1, num = 0;
		if (s[1] != ']') {
			for (int i = 1; s[i]; ++i) {
				if (s[i] == ',' || s[i] == ']')
					a[++r] = num, num = 0;
				else
					num = 10 * num + s[i] - '0';
			}
		}

		bool rev = false, err = false;
		for (int i = 0; p[i]; ++i) {
			if (p[i] == 'R') rev = !rev;
			else if (r < l) {
				err = true;
				break;
			}
			else if (rev) --r;
			else ++l;
		}

		if (err) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (rev) {
			for (int i = r; i >= l; --i) {
				cout << a[i];
				if (i != l) cout << ',';
			}
		}
		else {
			for (int i = l; i <= r; ++i) {
				cout << a[i];
				if (i != r) cout << ',';
			}
		}
		cout << "]\n";
	}
	return 0;
}