#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

vector<ii> adj[50001];
bool visit[50001];

iii findFarthestNode(int node, int dist, int times) {
	// (가장 멀리 있고, 최소 시간 합, 그 때의 정점 번호)
	iii ret = make_tuple( dist, times, node );
	visit[node] = true;
	for(auto& nextNode : adj[node]) {
		if (!visit[nextNode.first]) {
			iii guess = findFarthestNode(nextNode.first, dist + 1, times - nextNode.second);
			ret = max(ret, guess);
		}
	}
	return ret;
}

int main() {
	int i, n, t;
	scanf("%d %d", &n, &t);
	for (i = 0; i < n - 1; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		// (u-v) 로 연결된 Edge, 그리고 w의 가중치
		adj[u - 1].push_back({ v - 1, w });
		adj[v - 1].push_back({ u - 1, w });
	}

	// 임의의 한 점으로 부터 가장 먼 노드 V를 찾는다.
	memset(visit, false, sizeof(visit));
	auto find = findFarthestNode(0, 0, 0);
	int maxDist = get<0>(find);
	int farthestNode = get<2>(find);

	// 다시 V로부터 가장 먼 노드 U를 찾는다. 그것이 최대 지름
	memset(visit, false, sizeof(visit));
	find = findFarthestNode(farthestNode, 0, 0);
	int days = -get<1>(find);
	printf("%d", (days + t - 1) / t);
	return 0;
}