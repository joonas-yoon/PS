#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	long double l=0, r=3000000;
    for(int loop=0; loop < 10000; ++loop){
		long double x = (l + r) / 2;
		if(a*x + b*sin(x) < c)
			l = x;
		else
			r = x;
	}
	printf("%.6Lf", l);
	return 0;
}