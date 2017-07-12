#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d ", &n);
    vector<pair<string, int>> v(n);
    for(int i=0; i<n; ++i){
        char s[100001];
        scanf("%s ", s);
        v[i] = {s, i+1};
    }
    sort(v.begin(), v.end());
    for(auto& e : v){
        printf("%d ", e.second);
    }
    return 0;
}