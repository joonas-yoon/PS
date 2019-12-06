#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)

template <typename T>
class node {
public:
    node() {
        prev = next = NULL;
    }
    node(T dat) : data(dat) { prev = next = NULL; }
    ~node() { }
public:
    T data;
    node<T> *prev, *next;
};

int main() {
    fastio();

    int n, k;
    cin >> n >> k;
    node<int> a[5001];
    for (int i = 0; i < n; ++i) {
        a[i].data = i + 1;
        a[i].prev = &a[(i + n - 1) % n];
        a[i].next = &a[(i + 1) % n];
    }

    cout << "<";
    node<int> *cur = &a[n-1];
    for (int i = 0; i < n; ++i) {
        int loop = k % (n - i);
        for (int j = 0; j < loop; ++j) {
            cur = cur->next;
        }
        cout << cur->data << (i == n - 1 ? "" : ", ");
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->prev;
    }
    cout << ">";

    return 0;
}