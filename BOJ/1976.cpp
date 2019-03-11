#include <cstdio>

int group[201];

int find(int x) {
    if (group[x] == x) return x;
    return group[x] = find(group[x]);
}

// 병합 방향은 p <- q
void Union(int p, int q) {
    group[find(q)] = find(p);
}

int main() {
    int n, m, x;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        group[i] = i;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x);
            if (x == 1) {
                Union(i, j);
            }
        }
    }

    bool traveling = true;
    for (int i = 1; i < n; ++i) {
        traveling &= find(0) == find(i);
    }

    puts(traveling ? "YES" : "NO");

    return 0;
}