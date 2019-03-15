#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef map<int, int> mii;

void find(int& res, mii& dat){
    for(auto& a : dat){
        if(a.second != 2){
            res = a.first;
            return;
        }
    }
}

vector<int> solution(vector<vector<int> > v) {
    mii x, y;
    for(int i=0; i<3; ++i){
        x[v[i][0]]++;
        y[v[i][1]]++;
    }
    
    vector<int> ans(2);
    find(ans[0], x);
    find(ans[1], y);
    return ans;
}