#include <iostream>
using namespace std;

int main() {
	int n, tc = 0;
	while (cin >> n) {
		if (n == 0) break;

		char a, b, x, r = 0;
		bool var[26] = {1,0,};

		while (n--) {
			cin >> a >> x >> b;
			a -= 'a';
			b -= 'a';
			var[a] = var[b];
		}

		cout << "Program #" << ++tc << '\n';

		for (int i = 0; i < 26; ++i) {
			if (var[i]) {
				cout << (char)(i + 'a') << ' ';
				r = 1;
			}
		}
		if (!r) cout << "none";
		cout << "\n\n";
	}
	return 0;
}