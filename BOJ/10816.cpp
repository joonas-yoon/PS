#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(),(v).end()

vector<int> v;

int main() {
    int n, m;
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    sort(all(v));

    scanf("%d", &m);
    while (m--) {
        int x, r = 0;
        scanf("%d", &x);
        if (binary_search(all(v), x)) {
            r = upper_bound(all(v), x) - lower_bound(all(v), x);
        }
        printf("%d ", r);
    }

    return 0;
}