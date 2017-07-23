#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m, tn, tt, oid = 0;
	scanf("%d %d", &n, &m);
	vector<ii> v;
	while(n--){
		char cm[10];
		scanf("%s ", cm);
		if( !strcmp(cm, "order") ){
			scanf("%d %d", &tn, &tt);
			v.push_back({tt, tn});
		} else if( !strcmp(cm, "sort") ){
			sort(v.begin(), v.end());
		} else {
			scanf("%d ", &tn);
			vector<ii> newV;
			for(int i=0; i<v.size(); ++i){
				if(v[i].second != tn) newV.push_back(v[i]);
			}
			v = newV;
		}
		
		if( v.empty() ){
			puts("sleep");
			continue;
		}
		for(auto& t : v) printf("%d ", t.second);
		puts("");
	}
	return 0;
}