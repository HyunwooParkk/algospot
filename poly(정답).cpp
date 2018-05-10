#include <iostream>
#include <cstring>
using namespace std;
int N;
#define MOD 10000000
int cache[101][101];
int poly(int n, int first)
{
	if(n==first)
		return 1;

	int& ret=cache[n][first];
	if(ret!=-1)
		return ret;

	ret=0;
	for(int second=1; second<=n-first; second++)
	{
		int add=second+first-1;
		add *=poly(n-first,second);
		add %=MOD;
		ret +=add;
		ret %=MOD;
	}
	
	return ret;
}
int main(void)
{
	int C;
	int arr[100];
	scanf("%d",&C);

	for(int i=0; i<C ;i++)
	{
		scanf("%d",&N);

		int sum=0;
		memset(cache,-1,sizeof(cache));
		for(int j=1; j<=N; j++)
		{
			sum+=poly(N,j);
			sum %=MOD;
			arr[i]=sum;
		}
	}
	for(int i=0; i<C; i++)
		printf("%d\n",arr[i]);


}