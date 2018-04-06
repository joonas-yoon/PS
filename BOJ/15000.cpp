#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[1000001]={};
    scanf("%s ", s);
    for(int i=0; s[i]; ++i)
        putchar(s[i]-'a'+'A');
    return 0;
}