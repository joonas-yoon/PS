#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        printf("Case %d: ", tc);
        char s[201], ch;
        scanf("%s ", s);
        int len = 0;
        for (int i = 0; s[i]; ++i) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                for (int j = 0; j < len; ++j) putchar(ch);
                ch = s[i];
                len = 0;
            }
            else {
                len = 10 * len + s[i] - '0';
            }
        }
        for (int j = 0; j < len; ++j) putchar(ch);
        puts("");
    }
    return 0;
}