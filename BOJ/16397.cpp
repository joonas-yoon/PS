#include <bits/stdc++.h>
using namespace std;

string toString(int n) {
    if (n == 0) return "0";
    string s;
    while (n) {
        s = string(1, '0' + (n % 10)) + s;
        n /= 10;
    }
    return s;
}

int toInt(string& s) {
    int n = 0;
    for (int i = 0; i < s.length(); ++i){
        n = n * 10 + s[i] - '0';
    }
    return n;
}

int buttonB(int n) {
    if (2 * n > 99999) return -1;
    string s = toString(2 * n);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '0') {
            s[i]--;
            break;
        }
    }
    return toInt(s);
}

void solve(int n, int t, int g) {
    queue<int> q;
    q.push(n);
    bool v[100000] = {};
    v[n] = true;
    int ans = 0;
    while (!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int c = q.front();
            q.pop();

            if (c == g) {
                printf("%d\n", ans);
                return;
            }

            int nx[] = {c + 1, buttonB(c)};
            for (int i = 0; i < 2; ++i) {
                int next = nx[i];
                if (next < 0 || next > 99999 || v[next]) continue;
                v[next] = true;
                q.push(next);
            }
        }
        if (++ans > t) break;
    }
    puts("ANG");
}

int main() {
    int n, t, g;
    scanf("%d %d %d", &n, &t, &g);
    solve(n, t, g);
    return 0;
}