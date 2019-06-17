#include <string>
#include <vector>
#include <sstream> // stringstream
#include <algorithm> // sort
using namespace std;

using lld = long long;

struct Log {
	lld t;
	bool isEnd;
	int id;
	bool operator < (const Log& l) const {
		if (t == l.t) return id < l.id;
		return t < l.t;
	}
};

int get_duration(string s) {
	s.pop_back();
	stringstream ss(s);
	double d;
	ss >> d;
	return d * 1000;
}

lld stringToTime(string s) {
	int t[7] = {};
	int sum = 0, j = 0;
	for (int i = 0; i < s.length(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') sum = 10 * sum + s[i] - '0';
		else {
			t[j++] = sum;
			sum = 0;
		}
	}
	t[j] = sum;
	lld ret = 0, u = 1, unit[] = { 1000,60,60,24,1 };
	for (int i = 6; i > 1; u *= unit[6 - i], --i) {
		if (i == 2) t[i] -= 14;
		ret += t[i] * u;
	}
	return ret;
}

vector<Log> getLogs(vector<string>& lines) {
	vector<Log> logs;
	int id = 0;
	for (auto& s : lines) {
		string t;

		// parse duration
		int i = s.length();
		while (i-- > 0 && s[i] != ' ');

		lld tm = stringToTime(s.substr(0, i));
		logs.push_back({ tm - 1, true, id });
		tm -= get_duration(s.substr(i + 1));
		logs.push_back({ tm, false, id });
		id++;
	}
	return logs;
}

int solution(vector<string> lines) {
	vector<Log> logs = getLogs(lines);
	sort(logs.begin(), logs.end());

	int answer = 0, traffic = 0, sz = logs.size();

	for (int l = 0, r = 0; l < sz && r < sz; ) {
		while (l < sz && r < sz && logs[r].t - logs[l].t < 1000) {
			if (!logs[r].isEnd) traffic += 1, answer = max(answer, traffic);
			++r;
		}
		while (l < sz && r < sz && logs[r].t - logs[l].t >= 1000) {
			if (logs[l].isEnd) traffic -= 1;
			++l;
		}
	}

	return answer;
}