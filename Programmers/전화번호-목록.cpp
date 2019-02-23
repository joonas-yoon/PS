#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phones) {
    std::sort(phones.begin(), phones.end());
    for(int i=1; i<phones.size(); ++i){
        string& s = phones[i-1], &p = phones[i];
        int j = 0;
        while(j<s.length() && j<p.length() && s[j] == p[j]) j++;
        if(j == min(s.length(), p.length())) return false;
    }
    return true;
}