#include <stdio.h>
int c=0, C;
#define MAX 100000

// 각 스위치마다 연결된 시계를 1로 표현함
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

// 스위치에 연결된 각 시계의 시간을 3씩 증가시킴

void Check(int arr[], int num)
{
	int i;

		for(i=0; i<16; i++)
		{
			arr[i]=arr[i]+linked[num][i]*3;
			if(arr[i]==15)
				arr[i]=3;
		}
}

int IsComplete(int arr[])
{
	int i;

	for(i=0; i<16; i++)
	{
		if(arr[i]!=12)
			return 0;
	}
	return 1;
}


int PressSwitch(int arr[], int num)
{
	int i;
	int ret=0;
	int minCount=MAX;

	if(IsComplete(arr))
		return 0;
	if(num==10)
		return MAX;
	

	//0~3까지 반복함 그 이유는 4가 되면 결국 3*4=12이므로 원상태가 됨.
	for(i=0; i<4; i++)
	{	
		ret=PressSwitch(arr,num+1);
	
		if(minCount>(ret+i))
			minCount=ret+i;
		Check(arr,num);
	}
		printf("ret : %d\n",ret);
	return minCount;
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
		
		result=PressSwitch(arr,0);
		if(result==MAX)
			printf("-1\n");
		else
			printf("%d\n",result);
	}

	return 0;
}