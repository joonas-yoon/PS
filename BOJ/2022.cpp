#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

double a, b, c;

double g(double x, double k){
    double A = sqrt(a*a - k*k);
    return A - (A * x / k);
}

double f(double x, double k){
    return sqrt(b*b - k*k) * x / k;
}

int main(){
    while(~scanf("%lf %lf %lf", &a, &b, &c)){
        double l=0, r=min(a, b);
        
        while(r - l > 1e-9){
            double k = (l+r)/2.0;
            double c0 = k * c / sqrt(b*b - k*k);
            if(g(c0, k) > c){
                l = k;
            } else {
                r = k;
            }
        }
        
        printf("%.3lf\n", l);
    }
    return 0;
}
