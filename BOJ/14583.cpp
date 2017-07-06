#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	double H, W;
	scanf("%lf %lf", &W, &H);
	double Z = sqrt(H*H + W*W);
	double y = W*H / (W + Z);
	double ans_W = sqrt(W*W + y*y) / 2.0;
	printf("%.3lf %.3lf", ans_W, y * Z / ans_W / 2.0);
	return 0;
}