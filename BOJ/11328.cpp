#include <cstdio>

int main(){
    int n;
    scanf("%d ", &n);
    while(n--){
        char s[1001], p[1001];
        scanf("%s %s ", s, p);
        int f1[26]={}, f2[26]={};
        for(int i=0; s[i]; ++i) f1[s[i]-'a']++;
        for(int i=0; p[i]; ++i) f2[p[i]-'a']++;
        
        bool yes = true;
        for(int i=0; i<26; ++i) yes &= f1[i] == f2[i];
        puts(yes ? "Possible":"Impossible");
    }
    return 0;
}