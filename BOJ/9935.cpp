#include <iostream>
using namespace std;

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)

char s[1000001], p[40];
char res[1000001];

int main() {
    fastio();

    cin >> s >> p;
    int ri = 0, plen = 0, j;
    while (p[plen]) plen++;

    for (int i = 0; s[i]; ++i) {
        res[ri++] = s[i];
        for (j = 0; j < plen && ri - plen + j >= 0; ++j) {
            if (p[j] != res[ri - plen + j]) break;
        }
        if (j == plen) {
            ri -= plen;
            res[ri] = 0;
        }
    }
    res[ri] = 0;

    if (res[0]) cout << res << '\n';
    else cout << "FRULA\n";

    return 0;
}