#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::ios_base::sync_with_stdio(false); setbuf(stdout, 0); cin.tie(false)
#define all(v) (v).begin(),(v).end()

typedef pair<int, char> ch;

string str(string& s, vector<ch> v) {
    sort(all(v));
    string r;
    for (int i = 0; i < v.size(); ++i) {
        r.push_back(v[i].second);
    }
    return r;
}

bool comp(string& a, string& b) {
    if (a.length() == b.length()) return a < b;
    return a.length() > b.length();
}

int main() {
    fastio();
    string s;
    cin >> s;
    int len = s.length();

    vector<ch> prev;
    string ps;
    for (int z = 0; z < len; ++z) {
        vector<ch> temp(prev);
        vector<bool> used(len, false);
        for (int i = 0; i < prev.size(); ++i) {
            used[prev[i].first] = true;
        }

        for (int i = 0; i < len; ++i) {
            if (used[i]) continue;
            temp.push_back(make_pair(i, s[i]));
            string next = str(s, temp);
            if (comp(next, ps)) {
                ps = next;
                prev = temp;
            }
            temp.pop_back();
        }
        
        ps = str(s, prev);
        cout << ps << '\n';
    }

    return 0;
}