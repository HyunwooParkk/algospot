#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int arr[10][10];
int N;
int cache[10][10];
int check(int y, int x)
{
	if( y==N)
		return 0;

	int &ret =cache[y][x];

	if( ret != -1)
		return ret;

	ret=0;
	for(int i=0; i<2; i++)
		ret=max(ret,check(y+1,x+i)+arr[y][x]);
	
	return ret;

}
int main(void)
{
	int C;
	int result[10];
	cin >> C;
	for(int i=0; i<C; i++)
	{
		cin >> N;
		for(int j=0; j<N; j++)
			for(int k=0; k<j+1; k++)
				cin >> arr[j][k];
		memset(cache,-1,sizeof(cache));
		result[i]=check(0,0);
	}

	for(int i=0; i<C; i++)
		cout << result[i] << endl;
}