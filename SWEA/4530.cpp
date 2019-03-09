#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lld;

#define fastio() ios::ios_base::sync_with_stdio(false); setbuf(stdout, 0); cin.tie(false)
#define all(v) (v).begin(),(v).end()

lld solve(lld n) {
   int pt[] = {0,1,2,3,0,4,5,6,7,8};
   lld cr = 1, res = 0;
   for (; n; cr *= 9) {
      res += pt[n % 10] * cr;
      n /= 10;
   }
   return res;
}

int main() {
   fastio();

   int T;
   scanf("%d", &T);
   for (int tc = 1; tc <= T; ++tc) {
      lld a, b;
      scanf("%lld %lld", &a, &b);

      lld ans;
      if (a > 0 && b > 0) {
         ans = solve(b) - solve(a);
      } else if (a < 0 && b < 0) {
         ans = solve(-a) - solve(-b);
      } else { // a < 0 < b
         ans = solve(-a) + solve(b) - 1;
      }

      printf("#%d %lld\n", tc, ans);
   }

   return 0;
}