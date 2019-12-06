#include <iostream>
using namespace std;

#define fastio() std::cin.tie(NULL); std::ios::sync_with_stdio(false)

template <typename T>
class node {
public:
    node() {
        prev = next = NULL;
    }
    node(T dat) {
        data = dat;
        prev = next = NULL;
    }
public:
    T data;
    node<T> *prev, *next;
};

template <typename T>
class queue {
public:
    queue() {
        head = new node<T>();
        tail = new node<T>();
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }
    void push(T data) {
        node<T> *newNode = new node<T>(data);
        tail->prev->next = newNode;
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        ++sz;
    }
    void pop() {
        node<T> *del = head->next;
        del->next->prev = head;
        head->next = del->next;
        delete del;
        --sz;
    }
    int size() const {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
    T back() const {
        return tail->prev->data;
    }
    T front() const {
        return head->next->data;
    }
public:
    node<T> *head, *tail;
    int sz;
};

int main() {
    fastio();

    char c[6];
    int t, x;
    cin >> t;
    queue<int> q;
    while (t--) {
        cin >> c;
        if (c[0] == 's') cout << q.size() << '\n';
        else if (c[0] == 'e') cout << q.empty() << '\n';
        else if (c[1] == 'u') {
            cin >> x;
            q.push(x);
        }
        else if (q.empty()) cout << "-1\n";
        else {
            cout << (c[0] == 'b' ? q.back() : q.front()) << '\n';
            if (c[1] == 'o') q.pop();
        }
    }

    return 0;
}