#include <iostream>
#include <algorithm>
using namespace std;

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)

class point {
public:
    point() {
        a = b = c = d = -1;
    }
    point(int x, int y) : x(x), y(y) { a = b = c = d = -1; }
    bool operator < (const point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    int xpy() const {
        return x + y;
    }
    int xmy() const {
        return x - y;
    }
public:
    int x, y, idx;
    int a, b, c, d; // index
};

bool xpy(const point& a, const point& b) {
    if (a.xpy() == b.xpy()) return a < b;
    return a.xpy() < b.xpy();
}

bool xmy(const point& a, const point& b) {
    if (a.xmy() == b.xmy()) return a < b;
    return a.xmy() < b.xmy();
}

int len;
point v[100000];
point t[100000];
char step[100001];

int main() {
    fastio();

    int n, k;
    cin >> n >> k;
    cin >> step;
    for (int x, y, crs, i = 0; i < n; ++i) {
        cin >> x >> y;
        if (i == 0) crs = x + y;
        if (i > 0 && (x + y) % 2 != crs % 2) continue;
        v[len].x = x;
        v[len].y = y;
        v[len].idx = len;
        t[len] = v[len];
        len++;
    }

    sort(t, t + len, xpy);
    for (int i = 0; i + 1 < len; ++i) {
        if (t[i].xpy() == t[i + 1].xpy()) {
            int l = t[i].idx, r = t[i + 1].idx;
            v[l].b = r;
            v[r].c = l;
        }
    }

    sort(t, t + len, xmy);
    for (int i = 0; i + 1 < len; ++i) {
        if (t[i].xmy() == t[i + 1].xmy()) {
            int l = t[i].idx, r = t[i + 1].idx;
            v[l].a = r;
            v[r].d = l;
        }
    }

    int i = 0;
    for (int j = 0; j < k; ++j) {
        int next = v[i].d;
        if (step[j] == 'A') next = v[i].a;
        else if (step[j] == 'B') next = v[i].b;
        else if (step[j] == 'C') next = v[i].c;
        if (next == -1) continue;
        if (v[i].b >= 0) v[v[i].b].c = v[i].c;
        if (v[i].c >= 0) v[v[i].c].b = v[i].b;
        if (v[i].a >= 0) v[v[i].a].d = v[i].d;
        if (v[i].d >= 0) v[v[i].d].a = v[i].a;
        i = next;
    }

    cout << v[i].x << ' ' << v[i].y;

    return 0;
}