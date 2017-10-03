#include <bits/stdc++.h>
using namespace std;
 
typedef long long lld;
 
const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
 
lld max3(lld a, lld b, lld c) {
    return std::max(a, std::max(b, c));
}

struct Node {
    lld left, right, sum, middle;
    Node operator = (const lld& n) {
        sum = left = sum = middle = n;
        return *this;
    }
    Node getSum(const Node& l, const Node& r) {
        left = max3(
            l.sum, l.left,
            l.sum + r.left
        );
        right = max3(
            r.sum, r.right,
            l.right + r.sum
        );
        sum = l.sum + r.sum;
        middle = max3(
            l.middle, r.middle,
            l.right + r.left
        );
        return *this;
    }
    lld max() {
        return std::max(std::max(left, right), std::max(sum, middle));
    }
};

vector<lld> a;
vector<Node> tree;

// start from 1
Node init(int node, int l, int r) {
    if (l == r) {
        return tree[node] = a[l];
    }
    int mid = (l + r) / 2;
    return tree[node].getSum(init(node * 2, l, mid), init(node * 2 + 1, mid + 1, r));
}

Node update(int node, int l, int r, int idx, lld val) {
    if (idx < l || idx > r) return tree[node];
    if (l == r) return tree[node] = val;
    int mid = (l + r) / 2;
    return tree[node].getSum(update(node * 2, l, mid, idx, val), update(node * 2 + 1, mid + 1, r, idx, val));
}

// [l, r] 구간 트리의 [a, b] 쿼리
lld query(int node, int l, int r, int a, int b) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[node].max();
    int mid = (l + r) / 2;
    return max(query(node * 2, l, mid, a, b), query(node * 2 + 1, mid + 1, r, a, b));
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    a.resize(n + 1);
    int treeHeight = 1 << ((int)ceil(log2(n)) + 1);
    tree = vector<Node>(treeHeight + 1, { -INF, -INF, -INF });

    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    init(1, 1, n);

    while (q--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd) {
            printf("%lld\n", query(1, 1, n, 1, n));
        }
        else {
            int a, b;
            scanf("%d %d", &a, &b);
            update(1, 1, n, a, b);
        }
    }

    return 0;
}