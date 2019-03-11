#include <bits/stdc++.h>
using namespace std;

int n;
int nextV[100001];
vector<int> prevV[100001];
bool visit[100001];
stack<int> st;
vector<vector<int>> scc;

void predfs(int cur) {
    if (visit[cur]) return;
    visit[cur] = true;
    if (nextV[cur]) {
        predfs(nextV[cur]);
    }
    st.push(cur);
}

void dfs(vector<int>& res, int cur) {
    if (visit[cur]) return;
    visit[cur] = true;
    res.push_back(cur);
    for (int i = 0; i < prevV[cur].size(); ++i) {
        dfs(res, prevV[cur][i]);
    }
}

void makeSCC() {
    scc.clear();

    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i)
        predfs(i);

    memset(visit, false, sizeof(visit));
    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        vector<int> s;
        dfs(s, cur);
        if (!s.empty()) scc.push_back(s);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) prevV[i].clear();

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &nextV[i]);
            prevV[nextV[i]].push_back(i);
        }

        makeSCC();

        int cycle = 0;
        for (int i = 0; i < scc.size(); ++i) {
            if (scc[i].size() > 1) cycle += scc[i].size();
            else if (scc[i][0] == nextV[scc[i][0]]) cycle++;
        }
        printf("%d\n", n - cycle);
    }

    return 0;
}