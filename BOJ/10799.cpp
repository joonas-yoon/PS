#include <cstdio>

char s[100001];

int main() {
    scanf("%s", s);
    int ans = 0, top = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') top++;
        else {
            --top;
            if (s[i - 1] == ')') ans += 1;
            else ans += top;
        }
    }
    printf("%d\n", ans);

    return 0;
}