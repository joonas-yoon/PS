#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    deque<pair<int,int>> d;
    for(int i=0; i<priorities.size(); ++i){
        d.push_back(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    int cnt = 1;
    while(!pq.empty()){
        if(pq.top() == d.front().first){
            if(d.front().second == location)
                return cnt;
            d.pop_front();
            pq.pop();
            cnt++;
            continue;
        }
        d.push_back(d.front());
        d.pop_front();
    }
    return cnt;
}