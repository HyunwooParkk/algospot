#include <stdio.h>

int count[20];


int maxNum(int a, int b)
{
	int max;

	if(a>b)
		max=a;
	else
		max=b;

	return max;
}

int Check(int cc, int b)
{
	int i;
	int ret=0;
	int flag=-1,area;
	int max=0;

	if( b==cc)
		return max;

	for(i=b; i<cc; i++)
	{
		if(count[i] < count[b] )
		{
			flag=1;
			ret=i-b;
			break;
		}
		else if(i==cc-1)
		{
			flag=1;
			ret = i+1-b;
			break;
		}
	}
	
	max=Check(cc,b+1);
			 

	if(flag==1)
	{
		area=count[b]*ret;
		max=maxNum(area,max);
		return max;
	}
		
}

int main(void)
{
	int c,cc,i,min[100];
	int j;

	scanf("%d", &c);
	for(i=0; i<c; i++)
	{
		scanf("%d", &cc);
		for(j=0; j<cc; j++)
			scanf("%d", &count[j]);

		min[i]=Check(cc,0);
	}
	for(i=0; i<c; i++)
		printf("%d\n", min[i]);

	return 0;

}