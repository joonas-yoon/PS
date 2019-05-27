#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = max(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

long long treemax(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return max(treemax(tree, node * 2, start, (start + end) / 2, left, right), treemax(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    init(a, tree, 1, 0, n - 1);

    int r = 0, b = 0;
    for (int i = 1; i < n; ++i) {
        long long L = treemax(tree, 1, 0, n - 1, 0, i - 1);
        long long R = treemax(tree, 1, 0, n - 1, i, n - 1);
        r += L > R;
        b += L < R;
    }

    if (r == b) putchar('X');
    else if (r > b) putchar('R');
    else putchar('B');

    return 0;
}