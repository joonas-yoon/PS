#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    bool g[100][100]={};
    for(auto& r : results) {
        int a = r[0], b = r[1];
        g[a-1][b-1] = true;
    }
    
    for(int i=0; i<n; ++i) g[i][i] = true;
    
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            if(g[i][k] == false) continue;
            for(int j=0; j<n; ++j){
                g[i][j] |= g[i][k] & g[k][j];
            }
        }
    }
    
    int answer = 0;
    for(int i=0; i<n; ++i){
        bool connect = true;
        for(int j=0; j<n; ++j){
            connect &= g[i][j] || g[j][i];
        }
        answer += connect;
    }
    return answer;
}