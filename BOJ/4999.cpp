#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    cout << (s.length() < p.length() ? "no" : "go");
    return 0;
}