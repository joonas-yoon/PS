#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

const int MAX = 2 * 1e6;

void update(vector<int> &tree, int node, int start, int end, int i, int k) {
	if (i < start || i > end) return;
	tree[node] += k;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, i, k);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, k);
	}
}

int kth(vector<int> &tree, int node, int start, int end, int k) {
	if (start == end) {
		return start;
	}
	else {
		if (k <= tree[node * 2]) {
			return kth(tree, node * 2, start, (start + end) / 2, k);
		}
		else {
			return kth(tree, node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
		}
	}
}

int main() {
	int h = (int)ceil(log2(MAX + 1));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		update(tree, 1, 1, MAX, i, 1);
	}

	int restCount = n, mid = -1, leftPop = 0, rightPop = 0;
	if (n % 2 == 0) mid = n / 2 + 1;

	vector<ii> inputs(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &inputs[i].first, &inputs[i].second);
		if (mid < 0 && inputs[i].first == 1) {
			if (inputs[i].second > n / 2) mid = n / 2 + 1;
			else mid = n / 2 + 2;
		}
	}

	for(auto& in : inputs){
		int cmd = in.first, x = in.second;

		if (cmd == 1) {
			update(tree, 1, 1, MAX, x, -1);
			if (x < mid) leftPop++;
			else rightPop++;
			restCount -= 1;
		}
		else {
			int k, leftRest = mid - 1 - leftPop;
			if (x < mid) {
				if (mid - 1 - leftPop >= x) k = x;
				else k = INF;
			}
			else {
				k = x - (leftPop + rightPop);
				if (x <= mid + rightPop - 1) k = INF;
			}

			if (k == INF) puts("0");
			else {
				int ans = kth(tree, 1, 1, MAX, k);
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}