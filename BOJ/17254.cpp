#include <cstdio>
#include <algorithm>
using namespace std;

struct key {
    int id, t;
    char c;
    bool operator < (const key& o) const {
        if (t == o.t) return id < o.id;
        return t < o.t;
    }
};

int main() {
    int n, m;
    scanf("%d %d ", &n, &m);
    key k[1001];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c ", &k[i].id, &k[i].t, &k[i].c);
    }
    sort(k, k + m);
    for (int i = 0; i < m; ++i) printf("%c", k[i].c);

    return 0;
}