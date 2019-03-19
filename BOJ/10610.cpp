#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char s[100001];
    scanf("%s", s);
    int len = strlen(s);

    bool zero = false;
    for (int i = 0; s[i]; ++i) zero |= s[i] == '0';
    if (!zero) return puts("-1"), 0;

    int sum = 0;
    for (int i = 0; s[i]; ++i) {
        sum += s[i] - '0';
    }

    if (sum % 3 != 0) return puts("-1"), 0;
    sort(s, s + len);
    for (int i = 0; i < len; ++i) putchar(s[len - 1 - i]);

    return 0;
}