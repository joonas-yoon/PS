#include <cstdio>
#include <vector>
using namespace std;

typedef long long lld;

const int MAX = 8765432;
bool era[MAX + 1];
vector<int> primes;

int main() {
	era[0] = era[1] = true;
	for (int i = 2; i <= MAX; ++i) {
		if (era[i]) continue;
		for (lld j = i; j <= MAX; j += i) {
			era[j] = true;
		}
		primes.push_back(i);
	}

	int k;
	scanf("%d", &k);
	printf("%d\n", primes[k - 1]);

	return 0;
}
