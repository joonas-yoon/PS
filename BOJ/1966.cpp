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
class QUEUE {
public:
    QUEUE() {
        head = new node<T>();
        tail = new node<T>();
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }
    ~QUEUE() {
        node<T> *t = head;
        while (t) {
            node<T> *d = t;
            t = t->next;
            delete d;
        }
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

struct doc {
    int index, prior;
};

bool isTop(QUEUE<doc> &q) {
    if (q.empty()) return false;
    if (q.size() == 1) return true;
    node<doc> *p = q.head->next;
    int pr = p->data.prior;
    while (true) {
        p = p->next;
        if (p == q.tail) break;
        if (pr < p->data.prior) return false;
    }
    return true;
}

int main() {
    fastio();

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        QUEUE<doc> q;
        for (int pr, i = 0; i < n; ++i) {
            cin >> pr;
            q.push({ i, pr });
        }

        int cnt = 0;
        while (!q.empty()) {
            while (!isTop(q)) {
                q.push(q.front());
                q.pop();
            }
            ++cnt;
            if (q.front().index == m) break;
            q.pop();
        }
        cout << cnt << '\n';
    }

    return 0;
}