#include <stdio.h>

#define MAX 1000000
int linked[10][16] = {
    {1, 1, 1, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 1, 0 , 0 , 0 , 1 , 0 , 1 , 0, 1, 0, 0, 0, 0 },
    {0, 0, 0, 0, 1 , 0 , 0 , 0 , 0 , 0 , 1, 0, 0, 0, 1, 1 },
    {1, 0, 0, 0, 1 , 1 , 1 , 1 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 0, 0 , 0 , 1 , 1 , 1 , 0 , 1, 0, 1, 0, 0, 0 },
    {1, 0, 1, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
    {0, 0, 0, 1, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
    {0, 0, 0, 0, 1 , 1 , 0 , 1 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
    {0, 1, 1, 1, 1 , 1 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
    {0, 0, 0, 1, 1 , 1 , 0 , 0 , 0 , 1 , 0, 0, 0, 1, 0, 0 },
};
int c, C;
int ret;
void IsCheck(int Clock[], int num)
{
	int i;

	for(i=0; i<16; i++)
	{
		Clock[i]=Clock[i]+linked[num][i]*3;
		if(Clock[i]==15)
			Clock[i]=3;		
	}
}

int IsComplete(int Clock[])
{
	int i,j;

	for(i=0; i<16; i++)
	{
		if(Clock[i]!=12)
			return 0;
	}

	return 1;
}

int ClockComplete(int Clock[], int num)
{
	int i,j;
	int minCount=MAX;
	if(IsComplete(Clock))
		return 1;

	if(num==10)
		return 0;
	
	for(i=0; i<4; i++)
	{
		if(ClockComplete(Clock, num+1))
			ret+=1;
		//if(minCount>ret)
		//	minCount=ret;
		IsCheck(Clock,num);
	}

	return ret;
}

int main(void)
{
	int arr[16];
	int i,j;
	int result;

	scanf("%d",&C);
	for(j=0; j<C; j++)
	{
		for(i=0; i<16; i++)
			scanf("%d",&arr[i]);
		
		result=ClockComplete(arr,0);
		if(result==MAX)
			printf("-1\n");
		else
			printf("%d\n",result);
	}

	return 0;
}