#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef map<int, int> mii;

// 두번 등장하지 않은 수를 찾는다.
int find(mii& dat){
    for(auto& a : dat){
        if(a.second != 2){
            return a.first;
        }
    }
    // 사실 없는 경우는 없다.
    return -1;
}

vector<int> solution(vector<vector<int> > v) {
    mii x, y;
    for(int i=0; i<3; ++i){
        x[v[i][0]]++;
        y[v[i][1]]++;
    }
    
    vector<int> ans(2);
    ans[0] = find(x);
    ans[1] = find(y);
    return ans;
}