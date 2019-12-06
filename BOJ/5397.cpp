#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d ", &T);
    while(T--){
        char s[1000001];
        scanf("%s ", s);
        stack<char> left, right;
        for(int i=0; s[i]; ++i){
            if(s[i]=='-'){
                if(!left.empty()) left.pop();
            } else if(s[i]=='<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            } else if(s[i]=='>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
            } else left.push(s[i]);
        }
        char r[500001]={};
        int len=0;
        while(!left.empty()){
            r[len++] = left.top();
            left.pop();
        }
        for(int i=len-1; i>=0; --i) putchar(r[i]);
        while(!right.empty()){
            putchar(right.top());
            right.pop();
        }
        puts("");
    }
    return 0;
}