#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()
#define FOR(i,n) for(int i=0;i<n;++i)

const int INF = 0x3F3F3F3F;

int g[101][101];
int g1[101][101];

struct elem {
    int n, f;
    bool operator < (const elem& o) const {
        if (f == o.f) return n < o.n;
        return f < o.f;
    }
};

int solve(int y, int x, int goal) {
    int ans = 0, h = 3, w = 3;
    while (g[y][x] != goal) {
        if (++ans > 100) return -1;

        memset(g1, 0, sizeof(g1));
        int ph = h, pw = w;
        if (ph >= pw) {
            int tw = 0;
            FOR(i, ph) {
                map<int, int> fq;
                vector<elem> v;
                FOR(j, pw) if (g[i][j] != 0) fq[g[i][j]]++;
                for (auto& it : fq) {
                    v.push_back({it.first, it.second});
                }
                sort(all(v));
                int k = 0;
                for (auto& x : v) {
                    if (k < 100) g1[i][k++] = x.n;
                    if (k < 100) g1[i][k++] = x.f;
                }
                while (k > 0 && g1[i][k - 1] == 0) k--;
                tw = max(tw, min(100, k));
            }
            w = tw;
        } else {
            int th = h;
            FOR(i, pw) {
                map<int, int> fq;
                vector<elem> v;
                FOR(j, ph)  if (g[j][i] != 0) fq[g[j][i]]++;
                for (auto& it : fq) {
                    v.push_back({it.first, it.second});
                }
                sort(all(v));
                int k = 0;
                for (auto& x : v) {
                    if (k < 100) g1[k++][i] = x.n;
                    if (k < 100) g1[k++][i] = x.f;
                }
                while (k > 0 && g1[k - 1][i] == 0) k--;
                th = max(th, min(100, k));
            }
            h = th;
        }

        memcpy(g, g1, sizeof(g1));
    }
    return ans;
}

int main(){
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    FOR(i, 3) FOR(j, 3) scanf("%d", &g[i][j]);
    printf("%d\n", solve(r - 1, c - 1, k));
    return 0;
}