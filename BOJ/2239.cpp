#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

char s[10][10];

string possible(int y, int x) {
    bool fq[10] = {};
    for (int i = 0; i < 9; ++i) fq[s[y][i] - '0'] = 1;
    for (int i = 0; i < 9; ++i) fq[s[i][x] - '0'] = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fq[s[(y / 3) * 3 + i][(x / 3) * 3 + j] - '0'] = 1;
        }
    }
    string ret = "";
    for (int i = 1; i < 10; ++i) {
        if (fq[i] == false)
            ret.push_back('0' + i);
    }
    return ret;
}

vector<ii> blanks;

void solve(int cur) {
    // solved
    if (cur >= blanks.size()) {
        for (int i = 0; i < 9; ++i) puts(s[i]);
        exit(0);
        return;
    }

    int y = blanks[cur].first;
    int x = blanks[cur].second;

    string pos = possible(y, x);
    for (int k = 0; k < pos.length(); ++k) {
        s[y][x] = pos[k];
        solve(cur + 1);
        s[y][x] = '0';
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        scanf("%s ", s[i]);
        for (int j = 0; s[i][j]; ++j) {
            if (s[i][j] == '0') {
                blanks.push_back(make_pair(i, j));
            }
        }
    }

    solve(0);

    return 0;
}