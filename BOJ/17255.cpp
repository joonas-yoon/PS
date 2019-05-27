#include <iostream>
#include <string>
using namespace std;

string n;
bool numbers[10];

int solve(string& s) {
    if (n.compare(s) == 0) return 1;
    if (s.length() >= n.length()) return 0;

    int res = 0;
    for (int i = 0; i < 10; ++i) {
        if (!numbers[i]) continue;

        string ch(1, '0' + i);
        string left = s + ch;
        res += solve(left);

        string right = ch + s;
        if (left != right) {
            res += solve(right);
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n.length(); ++i) {
        numbers[n[i] - '0'] = true;
    }
    string str = "";
    cout<< solve(str) <<endl;
    return 0;
}