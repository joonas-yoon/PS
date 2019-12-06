#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)
#define FOR(i, n) for(int i=0;i<(n);++i)
#define all(v) (v).begin(), (v).end()
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,-1,0,1 };

struct Node {
    lld value, lazy;
};

// start from 1
lld init(vector<lld>& a, vector<Node>& tree, int node, int l, int r) {
    if (l == r) return tree[node].value = a[l];
    int mid = (l + r) / 2;
    return tree[node].value = init(a, tree, node * 2, l, mid) + init(a, tree, node * 2 + 1, mid + 1, r);
}

// [l, r] 구간 트리의 [a, b] 구간에 diff를 중첩 with Lazy propagation
void update_range(vector<Node>& tree, int node, int l, int r, int a, int b, lld diff) {
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    if (tree[node].lazy != 0) {
        lld& curLazy = tree[node].lazy;
        tree[node].value += (r - l + 1LL) * curLazy;
        if (l != r) {
            tree[leftNode].lazy += curLazy;
            tree[rightNode].lazy += curLazy;
        }
        curLazy = 0;
    }
    if (b < l || r < a) return;
    if (a <= l && r <= b) {
        tree[node].value += (r - l + 1LL) * diff;
        if (l != r) {
            tree[leftNode].lazy += diff;
            tree[rightNode].lazy += diff;
        }
        return;
    }
    int mid = (l + r) / 2;
    update_range(tree, leftNode, l, mid, a, b, diff);
    update_range(tree, rightNode, mid + 1, r, a, b, diff);
    tree[node].value = tree[leftNode].value + tree[rightNode].value;
}

lld update(vector<Node>& tree, int node, int l, int r, int idx, lld val) {
    if (idx < l || idx > r) return tree[node].value;
    if (l == r) return tree[node].value = val;
    int mid = (l + r) / 2;
    return tree[node].value = update(tree, node * 2, l, mid, idx, val) + update(tree, node * 2 + 1, mid + 1, r, idx, val);
}

lld update(vector<Node>& tree, int n, int idx, lld val) {
    return update(tree, 1, 1, n, idx, val);
}

// [l, r] 구간 트리의 [a, b] 쿼리 (합)
lld query(vector<Node>& tree, int node, int l, int r, int a, int b) {
    if (tree[node].lazy != 0) {
        tree[node].value += (r - l + 1LL) * tree[node].lazy;
        if (l != r) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[node].value;
    int mid = (l + r) / 2;
    return query(tree, node * 2, l, mid, a, b) + query(tree, node * 2 + 1, mid + 1, r, a, b);
}

lld query(vector<Node>& tree, int n, int a, int b) {
    return query(tree, 1, 1, n, a, b);
}

lld gcd(lld p, lld q) {
    return q ? gcd(q, p % q) : p;
}

// start from 1
lld gcd_init(vector<lld>& a, vector<Node>& tree, int node, int l, int r) {
    if (l == r) return tree[node].value = a[l];
    int mid = (l + r) / 2;
    return tree[node].value = gcd(
        gcd_init(a, tree, node * 2, l, mid),
        gcd_init(a, tree, node * 2 + 1, mid + 1, r)
    );
}

// [l, r] 구간 트리의 [a, b] 쿼리 (합)
lld gcd_query(vector<Node>& tree, int node, int l, int r, int a, int b) {
    if (tree[node].lazy != 0) {
        tree[node].value += (r - l + 1LL) * tree[node].lazy;
        if (l != r) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[node].value;
    int mid = (l + r) / 2;
    return gcd(
        gcd_query(tree, node * 2, l, mid, a, b),
        gcd_query(tree, node * 2 + 1, mid + 1, r, a, b)
    );
}

lld gcd_query(vector<Node>& tree, int n, int a, int b) {
    return gcd_query(tree, 1, 1, n, a, b);
}

vector<Node> tree, diff;

// Segment tree GCD — Range Update & Range Query
// gcd(a[l], a[l+1], ..., a[r]) = gcd(a[l], a[l+1] - a[l], a[l+2] - a[l+1], ..., a[r] - a[r-1])
// https://codeforces.com/blog/entry/9722
int main() {
    fastio();

    int n, m;
    scanf("%d", &n);
    vector<lld> a(n + 1), b(n + 1);
    int treeHeight = 1 << ((int)ceil(log2(n)) + 1);
    tree = vector<Node>(treeHeight, { 0, 0 });
    diff = vector<Node>(treeHeight, { 0, 0 });

    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i < n; ++i) b[i] = abs(a[i] - a[i + 1]);
    init(a, tree, 1, 1, n);
    gcd_init(b, diff, 1, 1, n);

    scanf("%d", &m);
    while (m--) {
        lld c;
        int l, r;
        scanf("%lld %d %d", &c, &l, &r);
        if (c == 0) {
            lld ranged = gcd_query(diff, n, l, r - 1);
            lld q = gcd(query(tree, n, l, l), ranged);
            printf("%lld\n", q);
        }
        else {
            update_range(tree, 1, 1, n, l, r, c);
            lld left = abs(query(tree, n, l - 1, l - 1) - query(tree, n, l, l));
            lld right = abs(query(tree, n, r, r) - query(tree, n, r + 1, r + 1));
            update(diff, n, l - 1, left);
            update(diff, n, r, right);
        }
    }
    return 0;
}