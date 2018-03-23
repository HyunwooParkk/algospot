#include <iostream>
using namespace std;
#define PI 10000000000000
int arr[100];
int cache[100][100];
int n;
void BubbleSort()
{
	int i,j;

	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

}

int Move(int start, int end)
{
	int sum=0;
	for(int i=start; i<=end; i++)
		sum+=arr[i];
	int avg=(int)((sum*1.0/(end-start+1)+0.5));

	int ret=0;
	for(int i=start; i<=end; i++)
		ret +=(avg-arr[i])*(avg-arr[i]);

	return ret;

}
int QuanTize(int start,int S)
{
	if(start==n)
		return 0;

	if(S==0)
		return PI;

	int& ret=cache[start][S];
	
	if(ret != -1)
		return ret;

	ret=PI;
	for(int i=start; i<n; i++)
		ret=min(ret,QuanTize(i+1,S-1)+Move(start, i));

	return ret;
}
int main(void)
{
	int C,b;
	int bb[100];
	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		scanf("%d %d", &n,&b);
		for(int j=0; j<n; j++)
		{
			cin >> arr[j];
		}
		for(int j=0; j<100;j++)
			for( int k=0; k<10; k++)
				cache[j][k]=-1;
		BubbleSort();

		bb[i]=QuanTize(0,b);
		
	}
	for(int i=0; i<C; i++)
		printf("%d\n", bb[i]);
}