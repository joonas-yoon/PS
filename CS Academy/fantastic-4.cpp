#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

// (a,b,c,d) 중에 a를 가장 크게 키워본다.
lld solve(vector<lld> a){
    lld k = min({a[1], a[2], a[3]});
    a[0] += 2*k;
    vector<lld> b(3);
    for(int i=0; i<3; ++i) b[i] = a[i+1] - k;
    sort(b.begin(), b.end());
    // b[0] is always 0
    /*
    b[] = {b, c, d}
     a  b  c  d
     1  0  ?  ?
    -1 +2 -1 -1
    +2 -1 -1 -1
    +2 -1 -1 -1
    ------------
    +3  0 -3 -3
    결과적으로 c와 d가 3씩 감소하고 a가 3 증가했다.
    그러기위해서는 c, d >= 3을 만족해야한다. 이미 b<=c<=d 이므로, c(b[1])/3이 옮겨질 횟수이다.
    */
    lld rest = a[0] > 0 ? b[1] / 3 : 0;
    a[0] += 3 * rest;
    b[1] -= 3 * rest;
    b[2] -= 3 * rest;
    return a[0] + (b[1] == 2);
}

int main() {
    lld a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    lld ans = 0;
    ans = max(ans, solve({a, b, c, d}));
    ans = max(ans, solve({b, a, c, d}));
    ans = max(ans, solve({c, b, a, d}));
    ans = max(ans, solve({d, b, c, a}));
    printf("%lld", ans);
    
    return 0;
}