#include <string>
#include <map>
using namespace std;

using lld = long long;

lld gcd(lld p, lld q) { return q ? gcd(q, p%q) : p; }

char toLower(char c) {
	if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
	return c;
}

int toNumber(char a, char b) {
	return (a - 'a') * 26 + b - 'a';
}

bool isAlpha(char x) {
	return 'a' <= x && x <= 'z';
}

map<int, lld> makeNumbers(string s) {
	map<int, lld> A;
	for (int i = 0, j = 1, sl = s.length(); i < sl; i += 2, j += 2) {
		if (i + 1 < sl && isAlpha(s[i]) && isAlpha(s[i + 1]))
			A[toNumber(s[i], s[i + 1])] += 1;
		if (j + 1 < sl && isAlpha(s[j]) && isAlpha(s[j + 1]))
			A[toNumber(s[j], s[j + 1])] += 1;
	}
	return A;
}

int solution(string s, string p) {
	for (auto& x : s) x = toLower(x);
	for (auto& x : p) x = toLower(x);

	map<int, lld> A = makeNumbers(s), B = makeNumbers(p);

	if (A.empty() && B.empty()) return s.compare(p) == 0 ? 65536 : 0;

	lld uniCnt = 0, intCnt = 0;
	for (auto& a : A) {
		auto it = B.find(a.first);
		if (it != B.end()) {
			uniCnt += max(a.second, it->second);
			intCnt += min(a.second, it->second);
		}
		else {
			uniCnt += a.second;
		}
	}
	for (auto& b : B) {
		auto it = A.find(b.first);
		if (it == A.end())
			uniCnt += b.second;
	}

	lld g = gcd(uniCnt, intCnt);
	uniCnt /= g;
	intCnt /= g;
	return (intCnt + 1e-12) / uniCnt * 65536;
}