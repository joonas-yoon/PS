#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    string s;
    cin >> s;
    stack<char> bracket;
    for (int i=0; i < s.length(); ++i){
        if (s[i]=='(') bracket.push(s[i]);
        else {
            bracket.pop();
            if (s[i-1] == ')') sum += 1;
            else sum += bracket.size();
        }
    }
    cout<< sum <<'\n';
    return 0;
}