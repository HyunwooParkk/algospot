#include <iostream>
using namespace std;

int arr[100][100];
int cache[100][100];
int cache1[100][100];
int N,M;

int Sum(int y, int x)
{
	if(y==N)
		return 0;

	int& ret=cache[y][x];

	if(ret != -1)
		return ret;
	ret=0;
	
	for(int i=0; i<2; i++)
		ret=max(ret,Sum(y+1,x+i)+arr[y][x]);

	return ret;
	
}

int TriPat(int y, int x)
{
	if(y==N-1)
		return 1;

	int& ret=cache1[y][x];

	if(ret != -1)
		return ret;
	ret=0;

	if(Sum(y+1, x+1) >= Sum(y+1, x))
		ret+=TriPat(y+1,x+1);
	if(Sum(y+1, x+1) <= Sum(y+1, x))
		ret+=TriPat(y+1,x);

	return ret;


}
int main(void)
{
	int C;
	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		scanf("%d",&N);
		for(int j=0; j<N; j++)
			for(int k=0; k<j+1; k++)
			{
				scanf("%d", &arr[j][k]);
				cache[j][k]=-1;
				cache1[j][k]=-1;
			}

		printf("%d\n", TriPat(0,0));

	}

	return 0;

}