#include <stdio.h>

int top=0;
int p[100]={0,};

void pushItem(int data)
{
	p[top++]=data;
}

void popItem()
{
	top--;
}

void pickPrint(int p[])
{
	int i=0;
	for(i=0; i<top; i++)
		printf("%d ",p[i]);
	printf("\n");
}
void pick(int n, int p[100],int index,int toPick)
{
	int i,smallest;
	if(toPick==0)
	{
		pickPrint(p);
		return;
	}
	
	smallest=index;
	for(i=smallest; i<n; i++)
	{
		pushItem(i);
		pick(n,p,i+1,toPick-1);
		popItem();
	}

}

int main(void)
{
	int i,j,k,l,num;
	int num1;

	printf("��� ���Ұ̴ϱ�?\n");
	scanf("%d", &num);
	printf("��� ���̴ϱ�?\n");
	scanf("%d", &num1);

	for(i=0; i<num; i++)
		p[i]=i;

	pick(num,p,0,num1);

	return 0;
}