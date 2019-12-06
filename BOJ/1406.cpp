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

char s[100001];

int main() {
    fastio();

    int n;
    cin >> s >> n;
    node<char> *head = new node<char>('^'); // head
    node<char> *cursor = head;
    for (int i = 0; s[i]; ++i) {
        cursor->next = new node<char>(s[i]);;
        cursor->next->prev = cursor;
        cursor = cursor->next;
    }
    node<char> *tail = new node<char>('$'); // tail
    tail->prev = cursor;
    cursor->next = tail;

    while (n--) {
        char c;
        cin >> c;
        if (c == 'P') {
            char x;
            cin >> x;
            node<char> *ch = new node<char>(x);
            cursor->next->prev = ch;
            ch->next = cursor->next;
            ch->prev = cursor;
            cursor->next = ch;
            cursor = ch;
        }
        else if (c == 'L') {
            if (cursor != head) cursor = cursor->prev;
        }
        else if (c == 'D') {
            if (cursor->next  != tail) cursor = cursor->next;
        }
        else if (cursor != head) {
            cursor->next->prev = cursor->prev;
            cursor->prev->next = cursor->next;
            cursor = cursor->prev;
        }
    }

    node<char> *cur = head->next;
    while (cur != tail) {
        cout << cur->data;
        cur = cur->next;
    }
    cout << '\n';

    return 0;
}