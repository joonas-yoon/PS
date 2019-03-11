#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

static int dy[]={-1,1,0,0};
static int dx[]={0,0,-1,1};

int h, w;
vector<vector<int>> pic;
bool visit[100][100];

int dfs(int y, int x, int type){
    if(visit[y][x] || pic[y][x] != type) return 0;
    visit[y][x] = true;
    
    int res = 1;
    for(int i=0; i<4; ++i){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        res += dfs(ny, nx, type);
    }
    return res;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // global vars
    h = m, w = n;
    pic = picture;
    memset(visit, 0, sizeof(visit));

    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
			if (pic[i][j] == 0) continue;
            int area = dfs(i, j, pic[i][j]);
            if(area > 0){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}