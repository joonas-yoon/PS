#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld fact(int n) {
    if (n <= 1) return 1;
    return fact(n - 1) * n;
}

int n;
bool use[21];

// [0, n)인 x번째 원소를 사용
int choose(int k) {
    for (int i = 0, j = 0; i < n; ++i) {
        j += use[i] == false;
        if (j == k + 1) {
            use[i] = true;
            return i + 1;
        }
    }
    return 0;
}

// 전체 사이즈가 n이고, k번째를 찾고 싶음
void print(int n, lld k) {
    if (n == 0) return;

    lld groupSize = fact(n - 1);
    lld index = k % groupSize;
    lld pos = k / groupSize;
    int here = choose(pos);
    printf("%d ", here);

    print(n - 1, index);
}

lld findKth(int *num) {
    lld ans = 0;
    // num[i]가 몇 번째 원소인지
    for (int i = 0; i < n; ++i) {
        lld nf = fact(n - 1 - i);
        int order = 0;
        for (int j = 0; j < num[i]; ++j) {
            order += use[j] == false;
        }
        use[num[i]] = true;
        ans += (order - 1LL) * nf;
    }
    return ans + 1;
}

int main() {
    int t;
    scanf("%d %d", &n, &t);

    if (t == 1) {
        lld k;
        scanf("%lld", &k);
        print(n, k - 1);
    } else {
        int num[21];
        for (int i = 0; i < n; ++i) scanf("%d", &num[i]);
        printf("%lld\n", findKth(num));
    }

    return 0;
}