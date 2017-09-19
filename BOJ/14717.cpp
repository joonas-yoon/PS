#include <bits/stdc++.h>
using namespace std;

int Rank(int a, int b) {
	if (a == b) return 100 + a;
	return (a + b) % 10;
}

int main() {
	int cards[11] = {};
	for (int i = 1; i <= 10; ++i) cards[i] = 2;
	int a, b;
	scanf("%d %d", &a, &b);
	cards[a] -= 1;
	cards[b] -= 1;
	vector<int> card;
	for (int c = 1; c <= 10; ++c) {
		for (int i = 0; i < cards[c]; ++i) card.push_back(c);
	}

	int ans = 0, myRank = Rank(a, b), allCount = 0;
	for (int i = 0; i < card.size(); ++i) {
		for (int j = i + 1; j < card.size(); ++j) {
			ans += myRank > Rank(card[i], card[j]);
			allCount += 1;
		}
	}
	printf("%.03lf\n", ans / (allCount + 1e-12));
	return 0;
}