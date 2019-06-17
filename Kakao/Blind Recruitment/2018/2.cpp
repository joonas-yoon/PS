#include <string>
#include <vector>
using namespace std;

using lld = long long;

struct Round {
	int score;
	char bonus, opt;
};

int powWithBonus(int k, char bns) {
	int x = 1, res = k;
	if (bns == 'D') x = 2;
	else if (bns == 'T') x = 3;
	while (--x > 0) res *= k;
	return res;
}

int solution(string dartResult) {
	vector<Round> v;
	int num = 0, len = dartResult.length();
	char bns = 0, opt = 0;
	bool cut = false;
	for (int i = 0; i < len; ++i) {
		char c = dartResult[i];
		if ('0' <= c && c <= '9') {
			if (cut) {
				v.push_back({ num, bns, opt });
				num = bns = opt = 0;
			}
			num = 10 * num + c - '0';
			cut = false;
		}
		else if ('A' <= c && c <= 'Z') bns = c, cut = true;
		else opt = c, cut = true;
	}
	v.push_back({ num, bns, opt });

	for (int i = 0; i < 3; ++i) {
		v[i].score = powWithBonus(v[i].score, v[i].bonus);
		if (v[i].opt == '#') {
			v[i].score *= -1;
		}
		if (v[i].opt == '*') {
			v[i].score *= 2;
			if (i > 0) v[i - 1].score *= 2;
		}
	}

	int answer = 0;
	for (auto& x : v) answer += x.score;
	return answer;
}