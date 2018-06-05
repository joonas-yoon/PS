/*
 * https://programmers.co.kr/tryouts/4510/challenges/13491

 * 정확성: 70.5
 * 효율성: 29.5
 * 합계: 100.0 / 100.0
 */

#include <iostream>
#include <vector>
using namespace std;

// 전파 도달 거리가 w라면, 길이가 l인 구간에 필요한 기지국  수
int need(int l, int w){
    if(l <= 0) return 0;
    int k = 2 * w + 1;
    return l / k + (l % k > 0);
}

int solution(int n, vector<int> stations, int w) {
    int ans = 0, p = 1;
    for(auto& x : stations){
        int l = x-w-1, r = x+w+1;
        if(p <= l)
            ans += need(l-p+1, w);
        p = r;
    }
    
    ans += need(n-p+1, w);
    return ans;
}