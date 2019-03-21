#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

struct user {
    int s, c, l, id;
    bool operator < (const user& r) {
        if (s == r.s) {
            if (c == r.c) return l < r.l;
            return c < r.c;
        }
        return s > r.s;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<user> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &v[i].s, &v[i].c, &v[i].l);
        v[i].id = i + 1;
    }
    sort(all(v));
    printf("%d\n", v[0].id);
    return 0;
}