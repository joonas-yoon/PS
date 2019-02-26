#include <cstdio>
#include <algorithm>
using namespace std;

int heap_size, heap[100001];

void push(int data) {
	heap[heap_size++] = data;
	int cur = heap_size - 1;
	while (cur > 0) {
		int parent = (cur - 1) / 2;
		if (heap[cur] > heap[parent]) {
			swap(heap[cur], heap[parent]);
		}
		cur = parent;
	}
}

void heapify(int root) {
	int l = 2 * (root + 1) - 1;
	int r = 2 * (root + 1);
	// 자식이 없는 경우
	if (l > heap_size) return;
	// 왼쪽만 있는 경우
	if (r > heap_size) {
		if (heap[root] < heap[l]) {
			swap(heap[root], heap[l]);
			heapify(l);
		}
		return;
	}
	// 둘 다 있는 경우, 더 큰 쪽과 교환
	if (heap[root] < max(heap[l], heap[r])) {
		if (heap[l] > heap[r]) {
			swap(heap[root], heap[l]);
			heapify(l);
		} else {
			swap(heap[root], heap[r]);
			heapify(r);
		}
	}
}

int pop() {
	if (heap_size == 0) return 0;

	int root = 0;
	int ret = heap[root];
	heap[root] = heap[--heap_size];
	heapify(root);
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", pop());
		} else {
			push(x);
		}
	}

	return 0;
}