#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, val;
    char str[8];
    scanf("%d ", &T);
    stack<int> s;
    while(T--){
        scanf("%s ", str);
        if(str[0]=='p' && str[1] == 'u'){
            scanf("%d ", &val);
            s.push(val);
        } else if(str[0]=='p' && str[1] == 'o'){
            if(s.empty()) val = -1;
            else {
                val = s.top();
                s.pop();
            }
            printf("%d\n", val);
        }
        else if(str[1] == 'i') printf("%d\n", (int)s.size());
        else if(str[1] == 'm') printf("%d\n", s.empty());
        else if(str[1] == 'o') printf("%d\n", s.empty()?-1:s.top());
    }
    return 0;
}