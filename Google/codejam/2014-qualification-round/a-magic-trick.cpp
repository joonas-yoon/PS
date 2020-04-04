#include <iostream>
#include <memory.h>
using namespace std;

bool cache[17]={0,};

void caching( int *arr ){
	for(int i=0; i < 4; ++i)
		cache[ arr[i] ] = true;
}

int complete( int *arr, int& res ){
	int find = 0;
	for(int i=0; i < 4; ++i){
		if( cache[ arr[i] ] ){
			find++;
			res = arr[i];
		}
	}

	memset( cache, 0, sizeof(cache) );
	return find;
}

int main()
{
	int nT, row, cards[4][4];
	cin >> nT;
	for(int T=1; T <= nT; ++T)
	{
		cin >> row;
		for(int i=0; i < 4; ++i)
			for(int j=0; j < 4; ++j)
				cin >> cards[i][j];

		caching( cards[row-1] );
		
		cin >> row;
		for(int i=0; i < 4; ++i)
			for(int j=0; j < 4; ++j)
				cin >> cards[i][j];
		
		int find = 0;
		int res = complete( cards[row-1], find );

		cout<<"Case #"<< T <<": ";
		if( res < 1 ) cout<<"Volunteer cheated!\n";
		else if( res == 1 ) cout<< find <<endl;
		else cout<<"Bad magician!\n";
	}

	return 0;
}