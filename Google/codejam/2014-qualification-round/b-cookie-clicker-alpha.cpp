#include <iostream>
using namespace std;

double calc(double C, double F, double X)
{
	double cookie = 2.0, total_s = 0.0;;
	double dirt_s = (double)X/cookie;
	double next_s = (double)C/cookie + (double)( X/(cookie+F) );
	while( dirt_s > next_s )
	{
		total_s += (double)C/cookie;
		cookie += F;
		dirt_s = (double)X/cookie;
		next_s = (double)C/cookie + (double)( X/(cookie+F) );
	}
	return (double)(total_s + dirt_s);
}

int main(){
	int nT;
	double C, F, X;
	cin >> nT;
	for(int t=1; t <= nT; ++t)
	{
		cin >> C >> F >> X;
		double result = calc( C, F, X );
		cout<<"Case #"<< t <<": ";
		cout<< fixed;	//소수점 고정
		cout.precision(7);        
		cout<< result <<endl;
	}

	return 0;
}