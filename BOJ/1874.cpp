#include <cstdio>
#include <stack>

int main() {
    int n, ai = 0, top = 1;
    char ans[200001];
    scanf("%d", &n);
    std::stack<int> s;
    for (int x, i = 0; i < n; ++i) {
        scanf("%d ", &x);
        while (top <= x) {
            ans[ai++] = '+';
            s.push(top++);
        }
        if (s.top() != x) 
            return puts("NO"), 0;

        ans[ai++] = '-';
        s.pop();
    }
    for (int i = 0; i < ai; ++i) printf("%c\n", ans[i]);
    return 0;
}