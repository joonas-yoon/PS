#include <bits/stdc++.h>
using namespace std;

static string symbols[] = {
    "ac", "ag", "al", "am", "ar", "as", "at", "au", "b", "ba", "be", "bh",
    "bi", "bk", "br", "c", "ca", "cd", "ce", "cf", "cl", "cm", "cn", "co",
    "cr", "cs", "cu", "db", "ds", "dy", "er", "es", "eu", "f", "fe", "fl",
    "fm", "fr", "ga", "gd", "ge", "h", "he", "hf", "hg", "ho", "hs", "i",
    "in", "ir", "k", "kr", "la", "li", "lr", "lu", "lv", "md", "mg", "mn",
    "mo", "mt", "n", "na", "nb", "nd", "ne", "ni", "no", "np", "o", "os",
    "p", "pa", "pb", "pd", "pm", "po", "pr", "pt", "pu", "ra", "rb", "re",
    "rf", "rg", "rh", "rn", "ru", "s", "sb", "sc", "se", "sg", "si", "sm",
    "sn", "sr", "ta", "tb", "tc", "te", "th", "ti", "tl", "tm", "u", "v",
    "w", "xe", "y", "yb", "zn", "zr"
};

bool next_chars[26][26];

int main() {
    setbuf(stdout, NULL);

    for (auto& s : symbols) {
        char ch = s.length() > 1 ? s[1] : s[0];
        next_chars[s[0] - 'a'][ch - 'a'] = true;
    }

    int T;
    scanf("%d ", &T);
    char s[50001];
    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d\n", tc);
        bool v[50001] = { true, };
        scanf("%s ", s);
        int len = strlen(s);
        for (int i = 0; s[i]; ++i) {
            if (v[i]) {
                if (next_chars[s[i] - 'a'][s[i] - 'a']) v[i + 1] = true;
                if (i + 1 < len && next_chars[s[i] - 'a'][s[i + 1] - 'a'])v[i + 2] = true;
            }
            if (!v[i] && !v[i + 1]) break;
        }
        puts(v[len] ? "YES" : "NO");
    }

    return 0;
}