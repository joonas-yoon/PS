#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

struct Node {
	lld value, lazy;
};

vector<lld> a;
vector<Node> tree;

// start from 1
lld init(int node, int l, int r) {
	if (l == r) return tree[node].value = a[l];
	int mid = (l + r) / 2;
	return tree[node].value = init(node * 2, l, mid) ^ init(node * 2 + 1, mid + 1, r);
}

lld update(int node, int l, int r, int idx, lld val) {
	if (idx < l || idx > r) return tree[node].value;
	if (l == r) return tree[node].value = val;
	int mid = (l + r) / 2;
	return tree[node].value = update(node * 2, l, mid, idx, val) ^ update(node * 2 + 1, mid + 1, r, idx, val);
}

// [l, r] 구간 트리의 [a, b] 구간에 diff를 중첩 with Lazy propagation
void update_range(int node, int l, int r, int a, int b, lld diff) {
	int leftNode = node * 2;
	int rightNode = node * 2 + 1;
	lld& curLazy = tree[node].lazy;
	if (curLazy != 0) {
		if ((r - l + 1) % 2) tree[node].value ^= curLazy;
		if (l != r) {
			tree[leftNode].lazy ^= curLazy;
			tree[rightNode].lazy ^= curLazy;
		}
		curLazy = 0;
	}
	if (b < l || r < a) return;
	if (a <= l && r <= b) {
		if ((r - l + 1) % 2) tree[node].value ^= diff;
		if (l != r) {
			tree[leftNode].lazy ^= diff;
			tree[rightNode].lazy ^= diff;
		}
		return;
	}
	int mid = (l + r) / 2;
	update_range(leftNode, l, mid, a, b, diff);
	update_range(rightNode, mid + 1, r, a, b, diff);

	tree[node].value = tree[leftNode].value ^ tree[rightNode].value;
}

// [l, r] 구간 트리의 [a, b] 쿼리 (합)
lld query(int node, int l, int r, int a, int b) {
	if (tree[node].lazy != 0) {
		if ((r - l + 1) % 2) tree[node].value ^= tree[node].lazy;
		if (l != r) {
			tree[node * 2].lazy ^= tree[node].lazy;
			tree[node * 2 + 1].lazy ^= tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (b < l || a > r) return 0;
	if (a <= l && r <= b) return tree[node].value;
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, a, b) ^ query(node * 2 + 1, mid + 1, r, a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	a.resize(n + 1);
	int treeHeight = 1 << ((int)ceil(log2(n)) + 1);
	tree = vector<Node>(treeHeight, { 0, 0 });

	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	init(1, 1, n);

	int q;
	scanf("%d", &q);
	while (q--) {
		int cmd, l, r;
		scanf("%d %d %d", &cmd, &l, &r); ++l, ++r;
        if(l > r) swap(l, r);
		if (cmd == 2) {
            printf("%lld\n", query(1, 1, n, l, r));
		}
		else {
			int v;
			scanf("%d", &v);
			update_range(1, 1, n, l, r, v);
		}
	}

	return 0;
}