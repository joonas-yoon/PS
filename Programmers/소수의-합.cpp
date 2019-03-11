#include <vector>

using namespace std;

#define MAX_N 10000000

int era[(MAX_N + 1) / 32];

long long solution(int N) {
    long long answer = 0;
    for(int i=2; i<=N; ++i){
        if(era[i / 32] & (1 << (i % 32))) continue;
        for(long long j=(long long)i*i; j<=N; j+=i){
            era[j / 32] |= 1 << (j % 32);
        }
        answer += i;
    }
    return answer;
}