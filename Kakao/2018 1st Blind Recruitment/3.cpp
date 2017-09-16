#include <string>
#include <vector>
#include <map>
using namespace std;

string& lowercase(string& s) {
	for (auto& c : s) {
		if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
	}
	return s;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (auto& c : cities) c = lowercase(c);

	map<string, int> idx;
	map<int, string> str;

	for (int i = 0; i < cities.size(); ++i) {
		string s = cities[i];
		if (idx.find(s) == idx.end()) {
			answer += 5;
			str[i] = s;
			idx[s] = i;
			if (str.size() > cacheSize) {
				int fir = str.begin()->first;
				string sec = str.begin()->second;
				str.erase(fir);
				idx.erase(sec);
			}
		}
		else {
			answer += 1;
			idx[s] = i;
			str[i] = s;
		}
	}
	return answer;
}