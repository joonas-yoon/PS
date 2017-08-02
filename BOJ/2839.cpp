#include <iostream>
using namespace std;

#define min(a, b) (a<b?a:b)
#define INF 987654321

int main(){
	int N, res = INF;
	cin >> N;
	for (int i = 0; i <= N / 3; ++i){
		for (int k = 0; k <= N / 5; ++k){
			if (3 * i + 5 * k == N){
				res = min(res, i + k);
			}
		}
	}
	cout<<( res < INF ? res : -1);
	return 0;
}