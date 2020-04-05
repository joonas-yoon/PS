#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <map>
using namespace std;

#define FOR(i, n) for(int i=0; i<(n); ++i)
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    char s[255]={};
    scanf("%s", s);
    int k = 0;
    for (int i=0; s[i]; ++i){
    for (int i=0; i<s[i]; ++i){
        for (; k < s[i] - '0'; ++k) putchar('(');
        for (; k > s[i] - '0'; --k) putchar(')');
        putchar(s[i]);
    }
    while (k--) putchar(')');
    puts("");
}

int main() {
    int T;
    scanf("%d ", &T);
    REP(tc, 1, T + 1) {
        printf("Case #%d: ", tc);
        solve();
    }
    return 0;
}