#include <bits/stdc++.h>
using namespace std;

#define LENGTH 3001

struct str {
    char s[LENGTH];
    int len;
};

void print(str *s) {
    for (int i = s->len - 1; i >= 0; --i) putchar(s->s[i]);
    puts("");
}

void fibo(int n) {
    str a, b, t;
    a = (str){"0", 1};
    b = (str){"1", 1};
    t = (str){"1", 1};

    str *pa = &a, *pb = &b, *pt = &t;
    while (n--) {
        int cr = 0, idx = 0;
        for (int i = 0, j = 0; pa->s[i] || pb->s[j] || cr > 0; i++, j++, cr /= 10) {
            if (pa->s[i]) cr += pa->s[i] - '0';
            if (pb->s[j]) cr += pb->s[j] - '0';
            pt->s[idx++] = '0' + (cr % 10);
        }
        pt->len = idx;
        pt = pa;
        pa = pb;
        pb = pt;
    }

    print(pa);
}

int main() {
    int n;
    scanf("%d", &n);
    fibo(n);
    return 0;
}