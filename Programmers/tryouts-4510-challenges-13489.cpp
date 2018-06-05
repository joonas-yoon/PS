/*
 * https://programmers.co.kr/tryouts/4510/challenges/13489
 
 * 정확성: 100.0
 * 효율성: 0.0
 * 합계: 100.0 / 100.0
 */

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

static bool _init = false;

bool isPalin(int n){
    char buf[10];
    sprintf(buf, "%d", n);
    for(int l=0, r=(int)strlen(buf)-1; l<r; ++l, --r){
        if(buf[l] != buf[r]) return false;
    }
    return true;
}

int palin[500001];

void init(int n, int m){
    if(_init) return;
    _init = true;
    int k = max(n, m);
    palin[0] = 1;
    for(int i=1; i<=k; ++i){
        palin[i] = palin[i-1] + isPalin(i);
    }
}

int solution(int n, int m) {
    init(n, m);
    return palin[m] - palin[n-1];
}