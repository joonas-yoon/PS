#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d ", &n);
        map<string, int> types;
        while (n--) {
            char name[21], type[21];
            scanf("%s %s ", name, type);
            types[type] += 1;
        }
        map<string, int>::iterator it = types.begin();
        lld ans = 1;
        for (; it != types.end(); ++it) {
            ans *= (it->second + 1);
        }
        printf("%lld\n", ans - 1);
    }

    return 0;
}