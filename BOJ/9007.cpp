#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::ios::sync_with_stdio(false)

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int n, k;
int arr[4][1001];

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &k, &n);
		vector<int> sum12, sum34;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < n; j++)
				scanf("%d ", &arr[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum12.push_back(arr[0][i] + arr[1][j]);
				sum34.push_back(arr[2][i] + arr[3][j]);
			}
		}

		sort(sum12.begin(), sum12.end());
		sort(sum34.begin(), sum34.end());
		sum34.erase(unique(sum34.begin(), sum34.end()), sum34.end());

		int diff = INF;
		bool isLeft = false;
		for (int i = 0; i < sum34.size(); i++) {
			int x = sum34[i];
			auto lb = lower_bound(sum12.begin(), sum12.end(), k - x);
			if (lb != sum12.end()) {
				int find = x + *lb;
				if (diff >= abs(k - find)) {
					if (diff == abs(k - find)) isLeft |= k > find;
					else isLeft = (k > find);
					diff = abs(k - find);
				}
			}
			if (lb != sum12.begin()) {
				lb--;
				int find = x + *lb;
				if (diff >= abs(k - find)) {
					if (diff == abs(k - find)) isLeft |= k > find;
					else isLeft = (k > find);
					diff = abs(k - find);
				}
			}
		}
		printf("%d\n", k + (isLeft ? -diff : diff));
	}
	return 0;
}