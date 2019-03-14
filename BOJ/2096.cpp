#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> adj[3] = {
    {0, 1}, {0,1,2}, {1,2}
};

int n, a[100001][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int maxsum[2][3] = {}, minsum[2][3] = {};
    for (int i = 1; i <= n; ++i) {
        int prev = (i + 1) % 2, cur = i % 2;
        for (int col = 0; col < 3; ++col) {
            int maxv = 0, minv = INF;
            for (int j = 0; j < adj[col].size(); ++j) {
                int c = adj[col][j];
                maxv = max(maxv, maxsum[prev][c]);
                minv = min(minv, minsum[prev][c]);
            }
            maxsum[cur][col] = a[i][col] + maxv;
            minsum[cur][col] = a[i][col] + minv;
        }
    }

    int maxv = 0, minv = INF;
    for (int i = 0; i < 3; ++i) maxv = max(maxv, maxsum[n % 2][i]);
    for (int i = 0; i < 3; ++i) minv = min(minv, minsum[n % 2][i]);
    printf("%d %d\n", maxv, minv);

    return 0;
}