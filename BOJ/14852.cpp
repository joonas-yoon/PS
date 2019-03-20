#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int f(int);
int g(int);

int dpf[1000001];
int dpg[1000001];

// g(n) = f(n-1)+f(n-2)+g(n-2)
int g(int n) {
    if (n < 1) return 0;
    if (n < 2) return 1;
    int& ret = dpg[n];
    if (ret != -1) return ret;
    ret = (f(n - 1) + f(n - 2)) % MOD;
    ret = (ret + g(n - 2)) % MOD;
    return ret;
}

// f(n) = f(n-2)+2*g(n)
int f(int n) {
    if (n < 0) return 0;
    if (n < 2) return n + 1;
    int& ret = dpf[n];
    if (ret != -1) return ret;
    ret = (2 * g(n)) % MOD;
    ret = (ret + f(n - 2)) % MOD;
    return ret;
}

int main() {
    memset(dpf, -1, sizeof(dpf));
    memset(dpg, -1, sizeof(dpg));

    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));

    return 0;
}