#include <bits/stdc++.h>
using namespace std;

string hex2bit(char ch) {
	int n = ch - '0';
	if (n > 9) n = ch - 'A' + 10;
	string r;
	for (; n > 0; n /= 2)
		r = string(1, '0' + n % 2) + r;
	while (r.size() < 4)
		r = string(1, '0') + r;
	return r;
}

char toHex(int n) {
	return n > 9 ? 'A' + n - 10 : '0' + n;
}

string int2str(int n, int scale, int len = 0) {
	if (n == 0) return "0";
	string r;
	for (; n > 0; n /= scale) r = string(1, toHex(n % scale)) + r;
	while (r.size() < len) r = "0" + r;
	return r;
}

char code2chr(int code) {
	return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:"[code];
}

int readNbit(string& bit, int& idx, int n) {
	int r = 0;
	for (int m = 1 << (n - 1); m > 0; m /= 2)
		r += m * (bit[idx++] - '0');
	return r;
}

int readCountBit(string& bit, int& idx, int mode) {
	static int b[] = { 10,9,8,0,8 };
	return readNbit(bit, idx, b[mode / 2]);
}

pair<int, vector<string>> solve(string& bit) {
	int cur = 0, size = 0;
	vector<string> ans;
	while (cur + 4 < bit.size()) {
		// read mode bits
		int mode = readNbit(bit, cur, 4);
		if (mode == 0) break;
		int countbit = readCountBit(bit, cur, mode);
		size += countbit;
		if (mode == 1) {
			int groups = (countbit - 1) / 3 + 1; // groups개의 묶음(숫자 3개씩)
			for (int k = 0; k < groups; ++k) {
				int _k = 3, bits[] = { 0,4,7,10 };
				if (k == groups - 1) _k = countbit % 3 ? countbit % 3 : 3;
				string thr = int2str(readNbit(bit, cur, bits[_k]), 10, _k);
				ans.push_back(thr);
			}
		}
		else if (mode == 2) {
			string chrs;
			for (int k = 0; k < countbit / 2; ++k) {
				int x = readNbit(bit, cur, 11);
				chrs.push_back(code2chr(x / 45));
				chrs.push_back(code2chr(x % 45));
			}
			if (countbit % 2) chrs.push_back(code2chr(readNbit(bit, cur, 6)));
			ans.push_back(chrs);
		}
		else if (mode == 4) {
			for (int k = 0; k < countbit; ++k) {
				int x = readNbit(bit, cur, 8);
				if (32 <= x && x <= 126)
					ans.push_back(string(1, x));
				else
					ans.push_back("\\" + int2str(x, 16, 2));
			}
		}
		else {
			for (int k = 0; k < countbit; ++k) {
				int x = readNbit(bit, cur, 13);
				if (32 <= x && x <= 126)
					ans.push_back(string(1, x));
				else {
					string h = int2str(x, 16);
					if (x < (1 << 12)) h = "0" + h;
					ans.push_back("#" + h);
				}
			}
		}
	}
	return make_pair(size, ans);
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		char s[40] = {};
		scanf("%s ", s);
		string fullbit;
		for (int i = 0; s[i]; ++i) fullbit += hex2bit(s[i]);
		auto ans = solve(fullbit);
		printf("%d ", ans.first);
		for (auto& x : ans.second) printf("%s", x.c_str());
		puts("");
	}
	return 0;
}