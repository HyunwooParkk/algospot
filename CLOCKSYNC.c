#include <stdio.h>
int c=0, C;
#define MAX 100000

// �� ����ġ���� ����� �ð踦 1�� ǥ����
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

// ����ġ�� ����� �� �ð��� �ð��� 3�� ������Ŵ

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
	

	//0~3���� �ݺ��� �� ������ 4�� �Ǹ� �ᱹ 3*4=12�̹Ƿ� �����°� ��.
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