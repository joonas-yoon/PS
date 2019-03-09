#include <cstdio>
#include <algorithm> // std::sort
using namespace std;

int L, C;
int length = 0;
char answer[20];
char alphabet[16];

// cur번째 알파벳을 선택하거나, 하지 않거나
void dfs(int cur, int selected = 0) {
	// L개를 선택한 경우는 출력
	if (selected >= L) {
		// 최소 한 개의 모음과 최소 두 개의 자음인 경우만 출력
		int vol = 0, con = 0;
		for (int i = 0; i < L; ++i) {
			char c = answer[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				vol++;
			else
				con++;
		}

		if (vol >= 1 && con >= 2) {
			puts(answer);
		}
		return;
	}

	if (cur >= C) return;

	// 선택한다
	answer[selected] = alphabet[cur];
	dfs(cur + 1, selected + 1);

	// 하지 않는다
	dfs(cur + 1, selected);
}

int main() {
	scanf("%d %d ", &L, &C);
	for (int i = 0; i < C; ++i) {
		scanf("%c ", &alphabet[i]);
	}
	
	// 알파벳순 정렬
	sort(alphabet, alphabet + C);

	dfs(0);

	return 0;
}