#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)

struct value {
    int x, idx;
};

int solve(char *s) {
    stack<char> ch;
    stack<value> v;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(' || s[i] == '[') ch.push(s[i]);
        else if (ch.empty()) return 0;
        else {
            char top = ch.top();
            if (top == '(' && s[i] != ')') return 0;
            if (top == '[' && s[i] != ']') return 0;

            int sum = 0;
            if ((s[i-1] == '(' && s[i] == ')') || (s[i-1] == '[' && s[i] == ']'))
                sum = 1;
            while (!v.empty() && v.top().idx == ch.size()) {
                sum += v.top().x;
                v.pop();
            }
            sum *= top == '(' ? 2 : 3;
            ch.pop();
            v.push({ sum, ch.size() });
        }
    }
    if (!ch.empty()) return 0;
    int ans = 0;
    for (; !v.empty(); v.pop()) ans += v.top().x;
    return ans;
}

int main() {
    fastio();

    char s[50];
    cin >> s;
    cout << solve(s) << '\n';

    return 0;
}