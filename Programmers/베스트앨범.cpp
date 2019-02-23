#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    map<string, int> gindex; // 장르 번호
    vector<pair<int, int>> gsize(100, make_pair(0, 0)); // 장르별 누적 재생 수, 장르번호
    vector<pair<int, int>> songs[100]; // (곡의 재생 수, 곡 번호)
    for(int i=0; i<n; ++i){
        if(gindex.count(genres[i]) == 0){
            int newID = gindex.size();
            gindex[genres[i]] = newID;
        }
        int gid = gindex[genres[i]];
        gsize[gid].first += plays[i];
        gsize[gid].second = gid;
        songs[gid].push_back(make_pair(plays[i], -i));
    }
    int size = gindex.size();
    vector<int> answer;
    sort(gsize.rbegin(), gsize.rend());
    for(int rid = 0; rid < size; ++rid){
        int gid = gsize[rid].second;
        sort(songs[gid].rbegin(), songs[gid].rend());
        for(int i=0; i<2 && i<songs[gid].size(); ++i){
            answer.push_back(-songs[gid][i].second);
        }
    }
    
    return answer;
}