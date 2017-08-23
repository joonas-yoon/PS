#include <bits/stdc++.h>
using namespace std;

string bigSum(string a, string b) {
	string r;
	int i = (int)a.length() - 1, j = (int)b.length() - 1;
	int sum = 0;
	for (; i >= 0 || j >= 0; i--, j--) {
		if (i >= 0) sum += a[i] - '0';
		if (j >= 0) sum += b[j] - '0';
		r = string(1, sum % 10 + '0') + r;
		sum /= 10;
	}
	if(sum > 0) r = string(1, sum + '0') + r;
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	string x = "5";
	for (int i = 1; i < n; ++i) {
		string cur = x;
		for (int j = 0; j < 4; ++j) x = bigSum(x, cur);
	}
	while ((int)x.size() < n) x = "0" + x;
	printf("0.%s", x.c_str());
	return 0;
}