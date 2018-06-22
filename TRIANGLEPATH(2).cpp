#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[101][101];
int cache[101][101];

int tri(int y, int x)
{
	if(y==N-1)
		return arr[y][x];

	int &ret= cache[y][x];
	if( ret != -1)
		return ret;

	return ret=max(tri(y+1,x),tri(y+1,x+1))+arr[y][x];
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
		result[i]=tri(0,0);

		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
				printf("%d",cache[j][k]);
			printf("\n");
		}
	}
	for(int i=0; i<C; i++)
		cout << result[i] << endl;

	return 0;

}