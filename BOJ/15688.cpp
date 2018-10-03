#include <cstdio>
#include <algorithm>

int arr[1000001];

int main() {
	int n, idx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[idx++]);
	}
	std::sort(arr, arr + n);
	for (int i = 0; i < n; ++i) printf("%d\n", arr[i]);
	return 0;
}