#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	vector<string> v;
	char ciph[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	while (getline(cin, s)) {
		if (!s.compare("START")) continue;
		if (!s.compare("ENDOFINPUT")) break;
		if (!s.compare("END")) {
			for (auto& line : v) {
				for (auto& c : line) {
					if (c >= 'A' && c <= 'Z') putchar(ciph[c - 'A']);
					else putchar(c);
				}
				puts("");
			}
			v.clear();
		}
		else v.push_back(s);
	}
	return 0;
}