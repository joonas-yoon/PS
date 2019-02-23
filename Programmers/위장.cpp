#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> kindof;
    vector<int> ref;
    for(auto& c : clothes){
        if(kindof.count(c[1]) == 0) {
            int sz =  kindof.size();
            kindof[c[1]] = sz;
            ref.push_back(0);
        }
        ref[kindof[c[1]]]++;
    }
    int answer = 1;
    for(auto& r : ref) answer *= (r + 1);
    return answer - 1;
}