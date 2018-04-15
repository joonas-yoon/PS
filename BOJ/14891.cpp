#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

// 조건: STL을 사용하지 않고 구현하기.

#define COG_LT true
#define COG_RT false

const int COG_LEN = 8;

char cog[4][10];
int pivot[4] = {}; // 12시 방향으로부터 시계방향으로 얼만큼 회전했는가

// id번 톱니바퀴의 left방향 톱니 하나의 극
char magnatic(int id, bool left) {
	int idx = (left ? pivot[id] + COG_LEN - 2 : pivot[id] + 2) % COG_LEN;
	return cog[id][idx];
}

// id번 톱니바퀴를 toLeft방향으로 회전시킨다.
void rotate(int id, bool toLeft) {
	pivot[id] = (pivot[id] + COG_LEN + (toLeft ? 1 : -1)) % COG_LEN;
}

void print() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < COG_LEN; ++j)
			putchar(cog[i][(j + COG_LEN + pivot[i]) % COG_LEN]);
		puts("");
	}
	puts("");
}

int main() {
	for (int i = 0; i < 4; ++i) scanf("%s ", cog[i]);

	int T, score = 0;
	scanf("%d ", &T);
	while (T--) {
		int id, dirt;
		scanf("%d %d", &id, &dirt);
		id--;
		bool toLeft = dirt == -1;

		// i와 i+1번의 연쇄 여부 (0: 반대로, 1: 그대로)
		// 다르면 반대방향, 같으면 안움직임
		bool stay[3] = {};
		for (int i = 0; i < 3; ++i) {
			stay[i] = magnatic(i, COG_RT) == magnatic(i + 1, COG_LT);
		}

		// 오른쪽 연쇄
		bool leftTurn = toLeft;
		for (int next = id + 1; next < 4; ++next) {
			int prev = next - 1;
			if (stay[prev]) break;
			leftTurn = !leftTurn;
			rotate(next, leftTurn);
		}

		// 왼쪽 연쇄
		leftTurn = toLeft;
		for (int next = id - 1; next >= 0; --next) {
			int prev = next + 1;
			if (stay[next]) break;
			leftTurn = !leftTurn;
			rotate(next, leftTurn);
		}

		rotate(id, toLeft);
	}

	// 점수 갱신
	for (int i = 0; i < 4; ++i) {
		score += (cog[i][pivot[i]] == '1') << i;
	}

	printf("%d\n", score);

	return 0;
}