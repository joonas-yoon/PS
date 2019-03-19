#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

struct point {
    int x, y;
};

double area(vector<point>& p) {
    lld sum = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        sum += p[i].x * (lld)p[j].y;
        sum -= p[j].x * (lld)p[i].y;
    }
    return abs(sum) / 2.;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    printf("%.1f\n", area(p));
    return 0;
}