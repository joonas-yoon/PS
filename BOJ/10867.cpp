#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    sort(all(v));
    for (int i = 0; i < n; ++i) {
        if (i > 0 && v[i - 1] == v[i]) continue;
        printf("%d ", v[i]);
    }

    return 0;
}