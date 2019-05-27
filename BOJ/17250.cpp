#include <iostream>
#include <algorithm>
using namespace std;

int gr[100001];
int sz[100001];

int find(int p) {
    if (gr[p] == p) return p;
    return (gr[p] = find(gr[p]));
}

int merge(int p, int q) {
    p = find(p);
    q = find(q);

    // 이미 같으면 그 크기를 리턴
    if (p == q) return sz[p];

    gr[p] = q; // p의 부모는 q
    sz[q] += sz[p]; // q의 크기에 p의 크기가 추가됨
    sz[p] = 0;
    return sz[q];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> sz[i];
        gr[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout<< merge(a, b) <<endl;
    }
    
    return 0;
}