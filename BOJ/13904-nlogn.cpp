#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

vector<ii> v;

// is it assigned the task on [k]-th day
bool isAssigned[1001];

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int d, w;
		scanf("%d %d", &d, &w);
		// 최대한 점수가 높은 것부터 처리하도록 점수에 대해 내림차순
		v.push_back(ii(-w, d));
	}
	
	std::sort(v.begin(), v.end());

	int sum = 0;
	for(int i=0; i<v.size(); ++i){
		// 점수가 높은 과제부터 과제를 하지 않은 가장 가까운 날짜에 배정
		for(int day=v[i].second; day>=1; --day){
			if(isAssigned[day] == false){
				isAssigned[day] = true;
				sum += -v[i].first;
				break;
			}
		}
	}
	printf("%d", sum);
	return 0;
}