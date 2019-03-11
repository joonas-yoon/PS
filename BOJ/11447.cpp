#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

double rad(double deg) {
    return PI * deg / 180;
}

struct point {
    double x, y;
};

// 신발끈 공식
double shoelace(vector<point>& p) {
    double area = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y;
        area -= p[j].x * p[i].y;
    }
    return abs(area) / 2;
}

int main() {
    point xyz[] = {
        {1, 0}, { 0.5, sin(rad(60))}, {-0.5, sin(rad(60))}
    };

    vector<point> units;
    for (int i = 0; i < 3; ++i) units.push_back(xyz[i]);
    double unitSize = 1.0 / shoelace(units);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d ", &n);
        vector<point> points;
        double x = 0, y = 0;
        while (n--) {
            char d;
            int len, idx = 0;
            scanf("%c %d ", &d, &len);
            if (d == 'x') idx = 0;
            if (d == 'y') idx = 1;
            if (d == 'z') idx = 2;

            x += len * xyz[idx].x;
            y += len * xyz[idx].y;

            points.push_back({x, y});
        }

        printf("%.0f\n", shoelace(points) * unitSize);
    }

    return 0;
}