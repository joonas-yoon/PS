#include <cstdio>
#include <vector>
#include <algorithm> // std::binary_search
using namespace std;

int main() {
    vector<int> num;
    
    for(int bit=(1<<20)-1; bit>0; bit--){
        int x = 0;
        for(int i=1,b=bit; b>0; b/=2, i*=3){
            if(b % 2) x += i;
        }
        num.push_back(x);
    }
    
    int n;
    scanf("%d", &n);
    puts(binary_search(num.rbegin(), num.rend(), n) ? "YES" : "NO");

    return 0;
}