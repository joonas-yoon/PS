// Problem 3
// Passed 25/30

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set_bit(int bit, int i) {
	return bit | (1 << i);
}

bool get_bit(int bit, int i) {
	return !!(bit & (1 << i));
}

int rows, cols;

bool check_unique(vector<vector<string>>& relation, int bit) {
	vector<string> r;
	for (auto& rec : relation) {
		string s = "";
		for (int i = 0; i < cols; ++i)
			if (get_bit(bit, i)) s += rec[i] + "-";
		r.push_back(s);
	}
	sort(r.begin(), r.end());
	for (int i = 1; i < r.size(); ++i)
		if (r[i] == r[i - 1]) return false;

	return true;
}

int vector_to_bit(vector<int>& v) {
	int bit = 0;
	for (int i = 0; i < v.size(); ++i) bit |= (v[i] != 0) << i;
	return bit;
}

int solution(vector<vector<string>> relation) {
	rows = relation.size();
	cols = relation[0].size();

	int answer = 0;

	// 각 컬럼이 후보키가 되기 위해 필요한 최소 컬럼 수
	vector<int> minb(cols, cols);

	for (int n = 1; n <= cols; ++n) {
		int subset = 0;
		vector<int> bitset(cols, 0);
		for (int i = 0; i < n; ++i) bitset[cols - 1 - i] = 1;

		do {
			int bit = vector_to_bit(bitset);

			// does not qualify for minimality
			bool minimality = true;
			for (int i = 0; minimality && i < cols; ++i) {
				if (get_bit(bit, i))
					minimality &= minb[i] >= n;
			}

			if (minimality && check_unique(relation, bit)) {
				answer++;
				for (int i = 0; i < cols; ++i) {
					if (get_bit(bit, i))
						minb[i] = n;
				}
			}
		} while (next_permutation(bitset.begin(), bitset.end()));
	}

	return answer;
}