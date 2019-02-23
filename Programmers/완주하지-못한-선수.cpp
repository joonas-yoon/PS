#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string> p;
    for(auto& s : participant) p.insert(s);
    for(auto& s : completion){
        p.erase(p.find(s));
    }
    return *p.begin();
}