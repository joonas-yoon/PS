#include <cstdio>
#include <algorithm>

int N, K, words[51];

inline int bitCount(int bit) {
	int sum = 0;
	while (bit > 0) {
		sum += (bit & 1);
		bit /= 2;
	}
	return sum;
}

// 2^k
int solve(int cur, int bit) {
	if (bitCount(bit) == K) {
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += (bit & words[i]) == words[i];
		}
		return sum;
	}

	int ret = 0;
	// 배우지 않은 알파벳을 배운다.
	for (int i = cur; i < 26; ++i) {
		if (((1 << i) & bit) == 0) {
			ret = std::max(ret, solve(i + 1, bit | (1 << i)));
		}
	}
	return ret;
}

int main() {
	scanf("%d %d ", &N, &K);
	for (int i = 0; i < N; ++i) {
		char s[16];
		scanf("%s", s);
		for (int j = 0; s[j]; ++j) words[i] |= 1 << (s[j] - 'a');
	}

	int ANTIC = 0;
	for (int i = 0; i < 5; ++i)
		ANTIC |= 1 << ("antic"[i] - 'a');
	printf("%d", solve(0, ANTIC));
	return 0;
}