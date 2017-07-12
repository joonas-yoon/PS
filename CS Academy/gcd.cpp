#include <iostream>
using namespace std;

int gcd(int p, int q){ return q ? gcd(q, p%q) : p; }

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}