#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> delay(n), indg(n, 0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &delay[i]);

        vector<int> adj[1001];
        while (k--) {
            int f, t;
            scanf("%d %d", &f, &t);
            adj[f - 1].push_back(t - 1);
            indg[t - 1] += 1;
        }

        queue<int> q;
        vector<int> sum(n, 0);
        for (int i = 0; i < n; ++i) {
            if (indg[i] == 0) {
                q.push(i);
                sum[i] += delay[i];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < adj[cur].size(); ++i) {
                int next = adj[cur][i];
                sum[next] = max(sum[next], sum[cur] + delay[next]);
                if (--indg[next] == 0) {
                    q.push(next);
                }
            }
        }

        int w;
        scanf("%d", &w);
        printf("%d\n", sum[w - 1]);
    }

    return 0;
}