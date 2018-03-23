#include <iostream>
#include <cstring>
#define MOD 1000000007;
using namespace std;
int N;
int arr[100];

int Tiling(int width)
{
	if(width <=0)
		return 1;

	int& ret=arr[width];

	if(ret != -1)
		return ret;
	
	return ret=(Tiling(width-2)+Tiling(width-1))%MOD;

}
int main(void)
{
	int C;
	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		scanf("%d", &N);

		memset(arr,-1,sizeof(arr));
		printf("%d\n", Tiling(N-1));

	}
}