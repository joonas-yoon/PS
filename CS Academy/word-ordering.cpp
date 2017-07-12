#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char p[53], order[53]={};
    scanf("%s %d ", p, &n);
    for(int i=0; i<26; ++i){
        order[p[i]-'a'] = 'A'+i;
    }
    for(int i=0; i<26; ++i){
        order[26+i] = order[i]-'A'+'a';
    }
    vector<string> origin;
    vector<pair<string, int>> v;
    for(int k=0; k<n; ++k){
        char s[1001];
        scanf("%s ", s);
        origin.push_back(s);
        for(int i=0; s[i]; ++i){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = order[s[i]-'a'];
            else
                s[i] = order[s[i]-'A'+26];
        }
        v.push_back({s, k});
    }
    
    sort(v.begin(), v.end());
    
    for(auto& s : v){
        puts(origin[s.second].c_str());
    }
    
    return 0;
}